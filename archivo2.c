#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 
main(int argc, char **argv[])

{
int fd;
char *c;
int resp;
fd = open("archivo.txt",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);//concatenamos por medio de or para definir el modo
//O_WRONLY abre el archivo salida.txt en modo escritura
//O_CREAT crea el archivo si todavía no existe
//S_IRUSR|S_IWUSR son los modos que seleccione: Lectura y Escritura para el usuario

scanf("%s",&c);//introducimos lo que se desea escribir en el archivo
if(sizeof(c) != -1){
printf("Se ha creado y acualizado correctamente\n");
write(fd,&c,sizeof(c));//Guardamos en el archivo lo que ingresamos por teclado

}
else{
printf("no se ha pudido editar el archivo\n\n\n");
}
printf("Desea borrar el archivo?\n");
printf("1.- si 0.-no\n");
scanf("%d",&resp);
if(resp == 1){
remove("archivo.txt");

if(fd == -1){
printf("no se ha podido borrar el archivo\n");
}
else{
printf("archivo aliminado correctamente");
}
}

close(fd);//cerrramos el archivo

}
