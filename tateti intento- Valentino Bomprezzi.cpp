#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include <windows.h>


void dTablero( char tablero[] ); //se declara el tablero 
void jugada(int *jugador, char tablero[]);// etablece el turno del jugador
int verificar( int *jugador, char a[] );//verificar valor

 
int main(void){
        int jugador = 1;
        char tablero[9] = "";
 
        dTablero( tablero );
        jugada( &jugador, tablero );
 
        return 0;
}
 
void dTablero( char tablero[] ){
        system( "CLS" );
        int a, b, c, d, e, f, g, h, i;
        
        
        printf("\n\n Tablero del Ta-Te-Ti\n\n");
        printf("\t|---+---+----+-|\n");
        printf("\t| 1%c | 2%c | 3%c |\n", tablero[0], tablero[1], tablero[2]);
        printf("\t|---+---+----+-|\n");
        printf("\t| 4%c | 5%c | 6%c |\n", tablero[3], tablero[4], tablero[5]);
        printf("\t|---+---+----+-|\n");
        printf("\t| 7%c | 8%c | 9%c |\n", tablero[6], tablero[7], tablero[8]);
        printf("\t|---+---+----+-|\n");
		
       
       
}

 
void jugada(int *jugador, char tablero[] ){
        int i, ch, ok, casillero, final = 0;
        int a, b, c, d, e, f, g, h, j;
	 		
        for( i = 0; i < 9; i++){
                do{
                        do{
                                dTablero( tablero );
                                printf( "\n\n\t ==> Jugador numero %d <==\n", *jugador );
                                printf( "\n Ingrece un entero del 1 al 9 para indicar el casillero a marcar...: " );
                                
                                ok = scanf( "%d", &casillero ) == 1 && casillero >= 1 && casillero <= 9;
                                
                                
                        }while(!ok);
                        //sustitucion d valor
       							a=casillero-1;
	        					b=casillero-2;
	        					c=casillero-3;
	        					d=casillero-4;
	        					e=casillero-5;
	        					f=casillero-6;
	        					g=casillero-7;
	        					h=casillero-8;
	        					j=casillero-9;
                        if( tablero[a] == 0 ){
                                if( *jugador == 1 ){
                                         
                                        if(tablero[a]==1){
                                        	tablero[a] ='X';
										}
										
                                        final = verificar( jugador, tablero );
                                        if (final == 0) *jugador = 2;
                                        
                                }
                                else{
                                        tablero[casillero-1] = '0';
                                        final = verificar( jugador, tablero );
                                        if (final == 0) *jugador = 1;
                                }
                        }
                        else{
                                ok = 0;
                                printf( "\n\n\t ==> Jugador numero %d <==\n", *jugador );
                                printf( "\n Ingrece un entero del 1 al 9 para indicar el casillero a marcar...: " );
                        }
                }while(!ok);
 
 
                if( final > 0 ){
                        dTablero( tablero );
                        printf( "\n\n !!! Ganador jugador numero %d !!!\n\n", *jugador );
                        break;
                }
        }
}
 
int verificar( int *jugador, char a[] ){
        int contarAciertos = 0, cj;
 
        if( *jugador == 1 )
                cj = 264 ;
        else
                cj = 144 ;
 
        if( a[0] + a[1] + a[2] == cj || a[3] + a[4] + a[5] == cj || a[6] + a[7] + a[8] == cj) contarAciertos++;
        if( a[0] + a[3] + a[6] == cj || a[1] + a[4] + a[7] == cj || a[2] + a[5] + a[8] == cj) contarAciertos++;
        if( a[0] + a[4] + a[8] == cj || a[2] + a[4] + a[6] == cj) contarAciertos++;
 
        return contarAciertos;
}
