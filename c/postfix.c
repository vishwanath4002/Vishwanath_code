#include <stdio.h>
#include <string.h>
#include <math.h>
struct stack
{
    double value;
}sv[15];
char infix[50],postfix[50];
char s[50];
int top=-1;

void pushchar(char o)
{
    top++;
    s[top]=o;
}
char popchar()
{
    char ch=s[top];
    top--;
    return ch;
}
int isoperator(char o)
{
    return (o == '+' || o == '-' || o == '*' || o == '/'|| o == '^');
}
int isoperand(char o)
{
    return ((o>='A'&&o<='Z')||(o>='a'&&o<='z'));
}
int precedence(char o)
{
    switch(o)
    {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;
        
        case '^':
            return 3;
    }
    return -1;
}
int infixtopostfix()
{
    int l=strlen(infix);
    int j=0;
    for(int i=0;i<l;i++)
    {
        if(infix[i]=='(')
        {
            pushchar(infix[i]);
        }
        else if(isoperand(infix[i]))
        {
            postfix[j]=infix[i];
            j++;
        }
        else if(infix[i]==')')
        {
            while(top>-1 && s[top]!='(')
            {
                postfix[j]=popchar();
                j++;
            }
            popchar();
        }
        else if(isoperator(infix[i]))
        {
            while(top>-1 &&(precedence(s[top])>=precedence(infix[i])))
            {
                postfix[j]=popchar();
                j++;
            }
            pushchar(infix[i]);
        }
    }
    while(top>-1)
    {
        if(s[top]=='(')
        {
            return 0;
        }
        postfix[j]=popchar();
        j++;
    }
    return 1;
}
void evaluate()
{
    int l=strlen(postfix);
    top=-1;
    for(int i=0;i<l;i++)
    {
        if(isoperand(postfix[i]))
        {
            double v;
            printf("\nEnter value for %c : ",postfix[i]);
            scanf("%lf",&v);
            top++;
            sv[top].value=v;
        }
        else
        {
            double a,b,r;
            b=sv[top].value;
            top--;
            a=sv[top].value;
            top--;            
            switch(postfix[i])
            {
                case '+':
                    r=a+b;
                    break;
                case '-':
                    r=a-b;
                    break;
                case '*':
                    r=a*b;
                    break;
                case '/':
                    if(b==0)
                    {
                        printf("Invalid values.");
                        return;
                    }
                    else
                    {
                        r=a/b;
                    }
                    break;
                case '^':
                    r=pow(a,b);
                    break;
            }
            top++;
            sv[top].value=r;
        }
    }
    printf("The result is : %f",sv[0].value);
    return;
}
void main()
{
    printf("Vishwanath Pradeep s3 CSE gamma\n");
    int ch;
    do
    {
        printf("\n1.Convert infix to postfix\n2.Convert infix to postfix and evaluate\n3.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        getchar();
        switch(ch)
        {
            case 1:
                printf("Enter the expression : ");
                gets(infix);
                if(infixtopostfix()==1)
                {
                    printf("The postfix form is : ");
                    puts(postfix);
                }
                else
                {
                    printf("Invalid expression.");
                }
                break;
            case 2:
                printf("Enter the expression : ");
                gets(infix);
                if(infixtopostfix()==1)
                {
                    printf("The postfix form is : ");
                    puts(postfix);
                    evaluate();
                }
                else
                {
                    printf("Invalid expression.");
                }
                break;
            case 3:
                break;
            default:
                printf("Invalid entry. Please try again.");
        }
        printf("\n");
    }while(ch!=3);
}