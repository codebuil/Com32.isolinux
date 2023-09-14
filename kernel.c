 int video;
 
 
 
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
        		   
			   char *a="hello world.... ";
			   video=0xb8000;
			   for(c=0;c<6;c++)
			   prints(a);
			   
			   
			   	
			   
			  
        }
 

