#include<iostream>

using namespace std;
class Nodo
{	
	private:
		int dato;
		Nodo *sig;
	public:
		Nodo()
		{	dato=0;
			sig=NULL;	
		}
		Nodo(int x)
		{	dato=x;
			sig=NULL;	
		}
		void Asignasig(Nodo*);
		void Leer(int);
		void Imprimir();
		Nodo *Obtienesig();
		int Obtienedato();
};
void Nodo::Asignasig(Nodo *x)
{	this->sig=x;
}
void Nodo::Leer(int x)
{	this->dato=x;
}
void Nodo::Imprimir()
{ cout<<this->dato<<endl;
}
Nodo* Nodo::Obtienesig()
{	return(this->sig);
}
int Nodo::Obtienedato()
{	return(this->dato);
}
class LSE
{	private:
		Nodo *Inicio;
	public:
		void InsertarI(int);
		void InsertarF(int);
		void Imprimir();
		LSE()
		{	Inicio=NULL;
		}
		void BorrarI();
		void BorrarF();
		int Contar();
		Nodo *Buscar(int);
		void Borrar(int);
};
void LSE::InsertarI(int a)
{
if(!Inicio)
{
    Inicio=new Nodo(a);
}else
{
	Nodo *A1=new Nodod(a);
	A1->Asignasig(Inicio);
	Inicio=A1;
}
}
void LSE::InsertarF(int a)
{
	if(Inicio==NULL)
	{
	Inicio=new Nodo(a);	
	}else
	{
	Nodo *A2=Inicio;
		while(A2->Obtienesig()!=NULL)
		{
			A2=A2->Obtienesig();
			Nodo *A3=new Nodod(a);
			A2->Asignasig(A3);
		}
	}
}
void LSE::BorrarI()
{
	if(!Inicio)
	{
	cout<<"La lista esta vacia"<<endl<<endl;
	}else
	{
	 if(Inicio->Obtienesig()==NULL)
	 {
	  delete Inicio;
	  Inicio=NULL;
	 }else
	 {
	 Nodo *A4=Inicio;
	 Inicio=Inicio->Obtiensig();
	 A4->Asignasig(NULL);
	 delete A4;
	 }
	}
}
void LSE::BorrarF()
{
	if(!Inicio)
	{
	 cout<<"La lista esta vacia"<<endl<<endl;	
	}else
	{
	 if(Inicio->Obtienesig()==NULL)
	 {
	 delete Inicio;
	 Inicio=NULL;
	 }else
	 {
	 Nodo *A5, *A6;
	 A5=A6;
	 while(A5->Obtienesig()==NULL)
	 {
	 A6=A5;
	 A5=A5->Obtienesig();
	 Inicio=NULL;
	 }
         A6->Asignasig(NULL);
	delete A6;
	 }
	}
}
void LSE::Imprimir()
{
if(!Inicio)
{
cout<<"La lista esta vacia"<<endl<<endl;	
}else
{
Nodo *A7=Incio;
	while(A7!=NULL)
	{
	A7->Imprimir();
		A7=A7->Obtienesig();
	}
}
}
int LSE::Contar()
{
int contar=0;
if(!Inicio)
{
contar=0;	
}else
{
Nodo *A8=Inicio;
	while(A8=NULL)
	{
	contar++;
	A8=A8->Obtienesig();
	}
}
	return contar;
}
Nodo* LSE::Buscar(int a)
{
Nodo *buscando=Inicio;
	if(Inicio)
	{
	while(buscando!=NULL)
	{
	if(buscando->Obtienedato()==a)	
	{
	return buscando;
		buscando=buscando->Obtiensig();
	}
	}
	}
	return buscando;
}
void LSE::Borrar(int a)
{
	Nodo *A9=Buscar(a);
	if(A9==NULL)
	{
	cout<<"El dato no fue encontrado"<<endl<<endl;	
	}else
	{
	if(A9==Inicio)
	{
	BorrarI();	
	}else
	{
	if(A9->Obtiensig()==NULL)
	{
	BorrarF();	
	}else
	{
	Nodo *borrando=Inicio;
		while(borrando->Obtienesig()!=A9)
		{
		borrando=borrando->Obtiensig();
			borrando->Asignasig(A9->Obtienesig());
			A9->Asignasig(NULL);
			delete A9;
		}
	}
	}
	}
}

int main(int argc, const char * argv[]/*¿Para que son estas variables?*/)
{
    LSE A;
    int opc, dato;
    do{
        cout<<"1.- Insertar Inicio"<<endl;
        cout<<"2.- Insertar Fin"<<endl;
        cout<<"3.- Borrar Inicio"<<endl;
        cout<<"4.- Borrar Fin"<<endl;
        cout<<"5.- Contar"<<endl;
        cout<<"6.- Borrar"<<endl;
        cout<<"7.- Imprimir"<<endl;
        cout<<"8.- Salir"<<endl;
        cout<<"Teclee la opcion"<<endl;
        cin>>opc;
        
        switch(opc)
        {
            case 1:
                cout<<"teclee el dato a insertar"<<endl;
                cin>>dato;
                A.InsertarI(dato);
                break;
            case 2:
                cout<<"Teclee el dato a insertar"<<endl;
                cin>>dato;
                A.InsertarF(dato);
                break;
            case 3:
                A.BorrarI();
                break;
            case 4:
                A.BorrarF();
                break;
            case 5:
                dato=A.Contar();
                cout<<"Hay "<<dato<<" nodos en la Lista"<<endl;
                break;
            case 6:
                cout<<"Teclee el dato a borrar"<<endl;
                cin>>dato;
                A.Borrar(dato);
                break;
            case 7:
                A.Imprimir();
                break;
            default:
                cout<<"opción salir...";
                break;
        }
    }while(opc<8);
    
    return 0;
}
