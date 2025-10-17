using System;
using System.Collections.Generic;

class Program
{
    struct Tarea
    {
        public string Descripcion;
        public bool Completada;

        public Tarea(string descripcion, bool completada)
        {
            Descripcion = descripcion;
            Completada = completada;
        }
    }

    static List<Tarea> tareas = new List<Tarea>();

    static void Main()
    {
        InicializarTareas();
        ListarTareasPendientes();
    }

    static void InicializarTareas()
    {
        tareas.Add(new Tarea("Hacer la tarea de matemáticas", false));
        tareas.Add(new Tarea("Comprar comida", true));
        tareas.Add(new Tarea("Estudiar para el examen", false));
    }

    static void ListarTareasPendientes()
    {
        Console.WriteLine("Tareas pendientes:\n");

        int contador = 0;
        for (int i = 0; i < tareas.Count; i++)
        {
            if (!tareas[i].Completada)
            {
                contador++;
                Console.WriteLine($"{contador}. {tareas[i].Descripcion}");
            }
        }

        if (contador == 0)
        {
            Console.WriteLine(" No hay tareas pendientes. ¡Buen trabajo!");
        }
    }
}