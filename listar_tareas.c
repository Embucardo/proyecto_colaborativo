using System;


class Program
{
    static string[] tareas = new string[50];
    static bool[] completadas = new bool[50];
    static int total = 0;


    static void Main()
    {
        tareas[0] = "Hacer la tarea de matemáticas";
        completadas[0] = false;


        tareas[1] = "Comprar comida";
        completadas[1] = true;


        total = 2;


        ListarTareas();
    }


    static void ListarTareas()
    {
        for (int i = 0; i < total; i++)
        {
            if (!completadas[i])
            {
                Console.WriteLine($"{i + 1}. {tareas[i]}");
            }
        }
    }
}
