    #include <stdio.h>
    #include <conio.h>
    struct details{
        char name[20];
        char usn[30];
        int marks;
        
    void display1(){
        printf("NAME:%s\n ",s1.name);
        printf("USN:%s\n ",s1.usn);
        printf("MARKS:%d\n ",s1.marks);
        }
    void display2(){
        printf("NAME:%s\n ",s2.name);
        printf("USN:%s\n ",s2.usn);
        printf("MARKS:%d\n ",s2.marks);
        }
    void compare(){
        if(s1.marks>s2.marks){
            printf(s1.name,"%s marks is greater than %s\n",s2.name);
        }
        else{
            printf(s2.name,"%s marks is greater than %s\n",s1.name);
        }
    }s1={"dia","1234",90},s2={"aadhya","1245",89};}
    void main(){
        details.display1();
        details.display2();
        details.compare();
    }
