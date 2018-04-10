#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;





double** matrix_product(double** A, int filas_A, int col_A, double** B, int filas_B, int col_B)
{
  //Declaro la matriz resultado
  
  double ** res = new double*[filas_A];

  for(int i = 0; i < filas_A; i++)
    {
      res[i] = new double[col_B];

      for(int k = 0; k < col_B; k++)
	{
	  //Inicializo a cero el resultado para asegurar la valides de los tres fors siguientes
	  res[i][k] = 0.0;
	}
    }

  //Inicializo cada elemento de la matriz resultado

  for (int i = 0; i < filas_A; i++)
    {
      for (int k = 0; k < col_B; k++)
	{

	  //Este ultimo for realiza la sumatoria necesaria para cada elemento (producto punto)
	  for (int n = 0; n < filas_B; n++)
	    {
	      res[i][k] += A[i][n] * B[n][k];
	    }
	}
    }

  return res; 
}


double** get_Matrix(int M, int N)
{
  int i;

  int k;

  //Incializo la matriz resultado

  double ** res = new double*[N];

  for(int i = 0; i < N; i++)
    {
      res[i] = new double[M];

      for(int k = 0; k < M; k++)
	{
	  //Lleno cada elemento de la matriz conc ceros
	 
	  res[i][k] = 0.0;
	}
    }

  //En este for inicializo los valores de la matriz
  
  for (i = 0; i < M; i++)
    {
      for (k = 0; k < N; k++)
	{
	  //Lleno cada elemento de la matriz pidiendole una entrada al usuario
	  int entrada = 0;
	  
	  cout << "Ingrese el elemento de la matriz ubicado en la fila " << i+1 << " y en la columna " << k+1 << endl;

	  cin >> res[i][k];
	}

    }

  //En este for imprimo la matriz llena

  cout << "A continuacion se mostrara la matriz completa :" << endl;

  for (i = 0; i < M; i++)
    {
      for (k = 0; k < N; k++)
	{
	  cout << res[i][k] << " ";
	}

      cout << endl;
    }
  

  return res;
}





int main()
{

  int filas_A;

  int col_A;

  int filas_B;

  int col_B;

  double** A;

  double** B;

  double** C;

  cout << "Ingrese el numero de filas de la matriz A " << endl;

  cin >> filas_A;

  cout << "Ingrese el numero de columnas de la matriz A " << endl;

  cin >> col_A;

  cout << "Ingrese el numero de filas de la matriz B" << endl;

  cin >> filas_B;

  if (col_A != filas_B)
    {
      cout << "El numero de columnas de A debe ser igual al numero de filas de B" << endl;

      return 0;
    }

  cout << "Ingrese el numero de columnas de la matriz B" << endl;

  cin >> col_B;

  cout << "Se inicializara la matriz A" << endl;

  A = get_Matrix(filas_A, col_A);

  cout << "Se inicializara la matriz B" << endl;

  B = get_Matrix(filas_B, col_B);

  C = matrix_product(A, filas_A, col_A, B, filas_B, col_B);

  
  cout << "Ahora se imprimira la matriz resultado del producto entre A y B" << endl;
    
  for (int i = 0; i < filas_A; i++)
    {
      for (int k = 0; k < col_B; k++)
	{
	  cout << C[i][k] << " ";
	}

      cout << endl;
    }  




  return 0;
}
