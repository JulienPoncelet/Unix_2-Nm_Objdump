#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int fd;
	struct stat stat_buf;
	size_t size;

	void *addr = NULL;
	void *save;
	char *str;
	struct mach_header_64 *mh;
	struct load_command *lc;
	struct symtab_command *sc;
	struct nlist_64 *nl;

	fd = open(argv[1], O_RDONLY);
	fstat(fd, &stat_buf);
	size = stat_buf.st_size;

	addr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, 0);
	save = addr;
	mh = (struct mach_header_64 *)addr;
	addr += sizeof(struct mach_header_64);
	for (int i = 0; i < mh->ncmds; i++)
	{
		lc = (struct load_command *)addr;
		printf("%p\n", lc);
		if (lc->cmd == LC_SYMTAB)
		{
			printf("%p\n", addr);
			sc = (struct symtab_command *)addr;
			printf("%p\n", sc);
			printf("\t%d\n", sc->symoff);
			save += sc->stroff + 2;
			printf("\t%p\n", save);
			for (int j = 0; j < sc->nsyms; j++)
			{
				str = (char *)save;
				printf("\t\t%s*\n", str);
				save += strlen(str) + 1;

			}
		}
		addr += lc->cmdsize;
	}
	munmap(addr, size);
	close(fd);
	return 0;
}
