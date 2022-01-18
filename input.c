#include "complex.c"

int handleline();
char * skipspace(char *str);
int checkcommand(char *str);
char * skipletters(char * str);
complex * checkcomp(char *str);
double checknumber(char *str);
char * skipnumbers(char *str);
int checkend(char * str);
int checktherest(char * str, int command);






int handleline()
{
    complex *second;
    complex *first;
    double firstnum, secondnum;
    char *p;
    char line[100];
    int command;


    printf("please insert you'r command & variables\n\n");
    fgets(line,100,stdin);
    p = (skipspace(line));
    if (checkcommand(p) == -1)
        return 1;
    command = checkcommand(p);
      if (command == 8)
    {
        printf("goooooodbye");
        return -1;
    }
    p = (skipletters(p));
    p = (skipspace(p));

    if (*p == 'A' || *p == 'B' || *p == 'C' || *p == 'D' || *p == 'E' || *p == 'F')
        first = checkcomp(p);
    else
    {
        printf("unknwon complex variable\n");
        return 1;
    }

    p = skipletters(p);
    
  
    if (command == 1 )
    {
        if (checkend(p) == 1)
             print_comp(first);
        else return 1;
    }
    if (command == 7)
    {
        if (checkend(p) == 1)
            abs_comp(first);
        else return 1;
    }

    if (command == 0 || command == 4  || command == 5)
    {
        p = skipspace(p);
        firstnum = checknumber(p);
        p = skipnumbers(p);

       
        
        if (command == 4)
        {
         if (checkend(p) == 1)
             mult_comp_real(first,firstnum);
        else return 1;
        }
        
            
        if (command == 5)
        {
             if (checkend(p) == 1)
                 mult_comp_img(first,firstnum);
               else return 1;
        }
       
        if (command == 0)
        {
            p = skipspace(p);
            secondnum = checknumber(p);
            p = skipnumbers(p);
            if (checkend(p) == 1)
            {
                read_comp(first,firstnum,secondnum);
                print_comp(first);
            }
            else return 1;
        }
    }


    if (command == 2 || command == 3 || command == 6)
    {   
        p=skipspace(p);
         if (*p == 'A' || *p == 'B' || *p == 'C' || *p == 'D' || *p == 'E' || *p == 'F')
        second = checkcomp(p);
    else
    {
        printf("unknwon complex variable\n");
    return 1;
    }
        p = skipletters(p);
        
        if (checkend(p) == 1)
        {  
        if (command == 2)
        add_comp(first,second);
        if (command == 3)
        sub_comp(first,second);
        if (command == 6)
        mult_comp_comp(first,second);
        }
        else return 1;
    }
return 1;
}



int checkcommand(char *s)
{
    char command[15];
    int j = 0;
    int d;
        while (isalpha(*s) || *s == '_')
        {
            command[j++] = *s;
           s++;
        }
        for (d = 0; d <= 8 ; d++)
        {
          if  (strncmp(command, commands[d], strlen(commands[d])) == 0)
        	{
         	return d;
        	}
        }
printf("undefined command\n");
return -1;
}

complex * checkcomp(char *str)
{
    switch (*str)
    {
    case ('A'):
        return &A;
    case ('B'):
        return &B;
    case ('C'):
        return &C;
    case ('D'):
        return &D;
    case ('E'):
        return &E;
    case ('F'):
        return &F;
    default:
       return NULL;
    }
}

double checknumber(char *str)
{
    return atof(str);
}

char * skipletters(char * s)
{
    int n;
    for (n = 0; (isalpha(s[n])|| s[n] == '_'); n++) {} 
    return s + n;
}
char * skipspace(char *s)
{
     int n;
    for (n = 0; (s[n] == ' ' || s[n] == '\t')|| s[n] == ','; n++) {} 
    return s + n;
}

char * skipnumbers(char *s)
{
int n;
    for (n = 0; (isdigit(s[n])|| s[n] == '.'|| s[n] == '-'); n++) {} 
    return s + n;
}

int checkend(char *s)
{
    if (strlen(s)==0)
     return 1;
    while (strlen(s)>0)
    {
        if (*s != ' ' || *s != '\t')
        {
            if (isdigit(*s))
            {
            printf("too many variables.\n");
            return -1;
            }
            if (isalpha(*s))
            {
            printf("too many complex numbers\n");
            return -1;
            }
            if (*s == ',')
            {
            printf("excessive comma.\n");
            return -1;
            }
            
        }
        s++;
    }
    return 1;
}
