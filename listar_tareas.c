using System;
using System.Collections.Generic;

class Tarea
{
    public string Descripcion { get; set; }
    public bool Completada { get; set; }

    public Tarea(string descripcion)
    {
        Descripcion = descripcion;
        Completada = false;
    }
}

class Program
{
    static List<Tarea> tareas = new List<Tarea>();

    static void Main()
    {
        Console.WriteLine("¿Cuántas tareas deseas ingresar?");
        string entrada = Console.ReadLine();

        if (!EsNumeroEntre(entrada, 1, 100))
        {
            Console.WriteLine("Cantidad inválida. Finalizando programa.");
            return;
        }

        int cantidad = int.Parse(entrada);

        for (int i = 0; i < cantidad; i++)
        {
            Console.Write($"Descripción de la tarea #{i + 1}: ");
            string descripcion = Console.ReadLine();

            if (string.IsNullOrWhiteSpace(descripcion))
            {
                Console.WriteLine("La descripción no puede estar vacía.");
                i--;
                continue;
            }

            if (!SoloLetras(descripcion))
            {
                Console.WriteLine("La descripción solo debe contener letras y espacios.");
                i--;
                continue;
            }

            tareas.Add(new Tarea(descripcion));
        }

        Console.Clear();
        ListarTareasPendientes();
    }

    static void ListarTareasPendientes()
    {
        Console.WriteLine("TAREAS PENDIENTES:\n");

        int contador = 0;
        foreach (var tarea in tareas)
        {
            if (!tarea.Completada)
            {
                contador++;
                Console.WriteLine($"{contador}. {tarea.Descripcion}");
            }
        }

        if (contador == 0)
        {
            Console.WriteLine("No hay tareas pendientes.");
        }
    }

    static bool SoloLetras(string texto)
    {
        foreach (char c in texto)
        {
            if (!char.IsLetter(c) && !char.IsWhiteSpace(c))
                return false;
        }
        return true;
    }

    static bool EsNumeroEntre(string entrada, int min, int max)
    {
        return int.TryParse(entrada, out int numero) && numero >= min && numero <= max;
    }
}