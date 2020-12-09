
int strlen(char *s);
int asciihexa2uint(char *s);
void uint2asciihexa(unsigned int d, char *s);

unsigned int x=165;
char s1[]="0x10A3";
char s2[]="l'hiver, c'est ≠ de l'été"; // 25 caractères + octet nul = 30 octets

char s[12];

int main() {
	int res = strlen(s1);
	
	res = asciihexa2uint(s1);
	
	uint2asciihexa(x, s);
	
	return 0;
}
