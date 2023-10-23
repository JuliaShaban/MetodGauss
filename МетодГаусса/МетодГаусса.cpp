#include"Gauss.h"


int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Количество уравнений: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n + 1));
    vector<vector<double>> MATRIX(n, vector<double>(n + 1));
    vector<vector<double>> A(n, vector<double>(n));
    vector<double> B(n);
    vector<double> q(n);


    cout << "Введите расширенную матрицу:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            MATRIX[i][j] = matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        B[i] = matrix[i][n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = matrix[i][j];
        }
    }
    gaussMetod(matrix);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            q[i] += A[i][j] * matrix[j][n];
        }

        MATRIX[i][n] = q[i];
    }



    gaussMetod(MATRIX);
    cout << "Решение :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i + 1 << "] = " << matrix[i][n] << endl;
    }
    vectorNev(A, B, matrix);

    double error = 0.0;
    for (int i = 0; i < n; i++)
    {
        error = max(error, abs(MATRIX[i][n] - matrix[i][n]) / abs(matrix[i][n]));
    }
    cout << "Error =" << error << endl;


    return 0;
}
