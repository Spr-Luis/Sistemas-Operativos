// ConsoleApplication1.cpp : Defines the entry point for the console application.
#include <windows.h>
#include <stdio.h>
#include <process.h>

// Funcion para los hilos

void ThreadProc(void *param);

// Primer Hilo

int main()

{

	int n;

	int i;

	int val = 0;

	HANDLE handle;

	printf("\t Hilos en Windows\n");

	printf("Ingrese el numero de hilos : ");

	scanf("%d", &n);

	for (i = 0; i<n; i++)

	{

		val = i + 1;

		handle = (HANDLE)_beginthread(ThreadProc, 0, &val); // Hilo creado

		WaitForSingleObject(handle, INFINITE);

	}

	system("pause");

}

void ThreadProc(void *param)

{

	int h = *((int*)param);

	printf("%d Hilo ejecutandose!\n", h);

	_endthread();

}
