 int video;
 typedef int size_t;
 int NULL;
 // Variável global para controlar o início da memória
static unsigned char *memoryStart;
 
 int *malloc(int length) {
    // Verifica se há espaço suficiente na memória
    unsigned char *memoryEnd = memoryStart + length + sizeof(int) * 2;
    if (memoryEnd > (unsigned char *)0x300000) {
        // Não há espaço suficiente
        return (int*)NULL;
    }

    // Preenche o bloco de memória com zeros
    //memfill(memoryStart, length + sizeof(int) * 2, 0);

    // Preenche o inteiro do cabeçalho
    *(int *)memoryStart = length;

    // Preenche o inteiro do rodapé
    *(int *)(memoryStart + length + sizeof(int)) = length;

    // Retorna o endereço após os inteiros do cabeçalho
    return (int *)(memoryStart + sizeof(int));
}

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
        		   char *b;
			   char *a="hello world.... ";
			   video=0xb8000;
			   memoryStart = (unsigned char *)0x200000;
			   NULL=0;
			   b=(char*)malloc(1025);
			   strcpys(b,a);
			   for(c=0;c<6;c++)
			   prints(b);
			   
			   
			   	
			   
			  
        }
 

