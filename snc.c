#include <stdio.h>
#include <stdint.h>

typedef union
{
struct
	{
	uint8_t d;
	uint8_t c;
	uint8_t b;
	uint8_t a;
	} parts;
uint32_t combined;
} i32;

int main()
{
i32 ipaddr;
unsigned char tmp;
printf("Podaj adres IP z maska(np. 192.168.0.1/24):");
scanf("%hhu.%hhu.%hhu.%hhu/%hhu", &ipaddr.parts.a, &ipaddr.parts.b, &ipaddr.parts.c, &ipaddr.parts.d, &tmp);
i32 netmask;
netmask.combined = ~0;
netmask.combined = netmask.combined << (32-tmp);
printf("\nAdres IP:%hhu.%hhu.%hhu.%hhu/", ipaddr.parts.a, ipaddr.parts.b, ipaddr.parts.c, ipaddr.parts.d);
for(tmp=31;netmask.combined&(1 << tmp);tmp--);
printf("%hhu\n", 31 - tmp);
if(ipaddr.combined&(1 << 31))
	{
	if(ipaddr.combined&(1 << 30)) printf("Klasa C\n");
	else printf("Klasa B\n");
	}
else printf("Klasa A\n");
i32 netaddr;
netaddr.combined = ipaddr.combined & netmask.combined;
printf("Adres sieci IP:%hhu.%hhu.%hhu.%hhu/", netaddr.parts.a, netaddr.parts.b, netaddr.parts.c, netaddr.parts.d);
printf("%hhu\n", 31 - tmp);
return 0;
}
