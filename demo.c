#include <stdio.h>

#ifdef __APPLE__
#define PRODUCT_NAME "PRODUCT,NAME"
#define PRODUCT_VERSION "PRODUCT,VERSION"
#else
#define PRODUCT_NAME "PRODUCT_NAME"
#define PRODUCT_VERSION "PRODUCT_VERSION"
#endif

#ifdef __GNUC__
char const PRODUCT_NAME_DATA[] __attribute__((used,section(PRODUCT_NAME))) = "demonstration";
char const PRODUCT_VERSION_DATA[] __attribute__((used,section(PRODUCT_VERSION))) = "UNSET";
#endif

int main(int argc, char** argv) {
	dprintf(1, "%s, version %s\n", PRODUCT_NAME_DATA, PRODUCT_VERSION_DATA);
	return 0;
}
