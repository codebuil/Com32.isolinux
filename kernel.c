 int video;
 typedef int size_t;
 
 
 // Função para contar o tamanho de uma string
size_t lens(const char* str) {
    size_t length = 0;
    while (*str) {
        length++;
        str++;
    }
    return length;
}

// Função para copiar uma string e adicionar seu comprimento ao valor
void strcpys(char* dest, const char* src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // Null-terminator
}
 void printc(char b)
        {
        		   int i=video;
			   char *fbp=(char* )i;
			   	*((char *)(fbp)) =(char)b;
			   	*((char *)(fbp+1)) =(char)0x17;
			   video++;
			   video++;  
        }

void prints(char *c)
{
	int counter=0;
	while(c[counter]!=0){
		printc(c[counter]);
		counter++;
	}
}

 void kernel_main()
        {
        		   int c=0;
        		   char b[120];
			   char *a="hello world.... ";
			   video=0xb8000;
			   strcpys(b,a);
			   for(c=0;c<6;c++)
			   prints(b);
			   
			   
			   	
			   
			  
        }
 

