 int video;
 typedef int size_t;
 int NULL;
 char *keymap;
 // Variável global para controlar o início da memória
static unsigned char *memoryStart;
 void memfill(void *dest, size_t length, unsigned char value) {
    // Cast o ponteiro para unsigned char* para permitir o preenchimento byte a byte
    unsigned char *d = (unsigned char *)dest;

    // Preencha os bytes da memória com o valor especificado
    for (size_t i = 0; i < length; i++) {
        d[i] = value;
    }
}

void memcopy(void *dest, const void *src, size_t length) {
    // Cast os ponteiros para unsigned char* para permitir a cópia byte a byte
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    // Copie os bytes de src para dest
    for (size_t i = 0; i < length; i++) {
        d[i] = s[i];
    }
}
 int *malloc(int length) {
    // Verifica se há espaço suficiente na memória
    unsigned char *memoryEnd = memoryStart + length + sizeof(int) * 2;
    if (memoryEnd > (unsigned char *)0x300000) {
        // Não há espaço suficiente
        return (int*)NULL;
    }

    // Preenche o bloco de memória com zeros
    memfill(memoryStart, length + sizeof(int) * 2, 0);

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

void cls(){

char *dest=(char* )0xb8000;
size_t length=4000;
unsigned int value=0x17;
    // Cast o ponteiro para unsigned char* para permitir o preenchimento byte a byte
    unsigned char *d = (unsigned char *)dest;

    // Preencha os bytes da memória com o valor especificado
    for (size_t i = 0; i < length; i=i+2) {
        d[i] = 32;
        d[i+1] = value;
    }
}
unsigned char getKeys() {
    unsigned char value;
    
    // Usando uma instrução asm inline para ler a porta 0x60
    asm volatile ("inb %1, %0" : "=a"(value) : "Nd"(0x60));
    
    return value;
}
// Função para obter uma string até que a tecla "Enter" seja pressionada
char* getstring() {
    char* buffer = (char*)NULL;
    char* tempBuffer = (char*)NULL;
    int bufferSize = 0;
    int bufferLength = 0;
    char character ;

    while (1) {
        // Obtém a tecla atual
        unsigned char key = getKeys();

        // Verifica se a tecla é "Enter" (0x1C)
        

        // Converte a tecla para caractere e a coloca no buffer
        
        if (key<127){
        key=key;
        if (key == 0x1C) {
            break; // Tecla "Enter" pressionada, saia do loop
        }
        
            character = keymap[key];
            if (bufferSize == 0) {
                bufferSize = 1025;
                buffer = (char*)malloc(1025);
                if (buffer == (char*)NULL) {
                    return (char*)NULL; // Falha na alocação de memória
                }
            }
            /*
            if (bufferLength + 1 >= bufferSize) {
                // Redimensiona o buffer conforme necessário
                bufferSize *= 2;
                tempBuffer = (char*)realloc(buffer, bufferSize);
                if (tempBuffer == NULL) {
                    free(buffer);
                    return NULL; // Falha na realocação de memória
                }
                buffer = tempBuffer;
            }
            */
            buffer[bufferLength++] = character;
            printc(character);
            buffer[bufferLength] = '\0'; // Null-terminate a string
            while(!(getKeys()>127)){}
        }
        }
        
    

    return buffer;
}
void gets(){
while(1){
	if(getKeys()<127){
	printc(keymap[getKeys()]);
	
	}else{
	printc(32);	
	}
	video--;
	video--;
}}

 void kernel_main()
        {
        		   int c=0;
        		   char *b;
			   char *a="intruduza o seu texto?: ";
			   video=0xb8000;
			   keymap="==1234567890-===qwertyuiop====asdfghjkl====\\zxcvbnm,.;/==== ";
			   memoryStart = (unsigned char *)0x200000;
			   NULL=0;
			   b=(char*)malloc(1025);
			   strcpys(b,a);
			   cls();
			   prints(b);
			   b=getstring();
			   video++;
			   video++;
			   prints(b);
			   
			   
			   	
			   
			  
        }
 

