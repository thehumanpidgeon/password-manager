struct passwords{
    char *service;
    char *cryptText;
};

char serviceChoice(void);
char * findFile(void);
void encrypt(char *,char *,char *);
char * decrypt(char *,char *);
struct passwords * readFile(char *);