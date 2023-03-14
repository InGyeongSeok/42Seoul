#include <stdio.h>

int ft_isalpha(int c)
{
    if(c >= 'A' && c <= 'Z'){
        return 1;
    }
    else if(c >='a' && c <= 'z'){
        return 2;
    }
    else
        return 0;
}

int ft_isdigit(int c)
{
    if(c >= '0' && c <= '9'){
        return 1;
    }
    else{
        return 0;
    }
}

int ft_isalnum(int c)
{
    if(ft_isalpha(c)==1){
        return 1;
    }
    else if(ft_isalpha(c)==2){
        return 2;
    }
    else if(ft_isdigit(c)==1){
        return 4;
    }
    else
        return 0;
}

int main()
{
    printf("%d\n", ft_isalnum('4'));
    printf("%d", isalnum('#'));
}