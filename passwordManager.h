struct passwords{
    char *service;
    char *cryptText;
};

char serviceChoice(void);
char * findFile(void);
void encrypt(char *,char *);
unsigned char * hash(char *);
char * decrypt(char *,char *);
struct passwords * readFile(char *);
void writeFile(struct passwords);