#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

template <typename T, int N, int M>
class Matrix {
private:
    T data[N][M];

public:
    Matrix() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                data[i][j] = 0;
            }
        }
    }

    T& at(int i, int j) {
        return data[i][j];
    }

    const T& at(int i, int j) const {
        return data[i][j];
    }

    Matrix<T, N, M> operator+(const Matrix<T, N, M>& autre) const {
        Matrix<T, N, M> resultat;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                resultat.data[i][j] = data[i][j] + autre.data[i][j];
            }
        }

        return resultat;
    }

    template <int P>
    Matrix<T, N, P> operator*(const Matrix<T, M, P>& autre) const {
        Matrix<T, N, P> resultat;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < P; j++) {
                for (int k = 0; k < M; k++) {
                    resultat.data[i][j] += data[i][k] * autre.data[k][j];
                }
            }
        }

        return resultat;
    }

    friend ostream& operator<<(ostream& os, const Matrix<T, N, M>& matrice) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                os << matrice.data[i][j] << "\t";
            }
            os << endl;
        }

        return os;
    }
};

#endif
