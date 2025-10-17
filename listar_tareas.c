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
        int cantidad = 0;

        while (true)
        {
            Console.Write("¿Cuántas tareas deseas ingresar? (1-100): ");
            string entrada = Console.ReadLine();

            if (string.IsNullOrWhiteSpace(entrada))
            {
                Console.WriteLine("La entrada no puede estar vacía.");
                continue;
            }

            if (!EsNumeroEntre(entrada, 1, 100))
            {
                Console.WriteLine("Debes ingresar un número entre 1 y 100.");
                continue;
            }

            cantidad = int.Parse(entrada);
            break;
        }

        for (int i = 0; i < cantidad; i++)
        {
            while (true)
            {
                Console.Write($"Descripción de la tarea #{i + 1}: ");
                string descripcion = Console.ReadLine();

                if (string.IsNullOrWhiteSpace(descripcion))
                {
                    Console.WriteLine("La descripción no puede estar vacía.");
                    continue;
                }

                if (!SoloLetras(descripcion))
                {
                    Console.WriteLine("La descripción solo debe contener letras y espacios.");
                    continue;
                }

                if (descripcion.Length > 50)
                {
                    Console.WriteLine("La descripción no debe exceder los 50 caracteres.");
                    continue;
                }

                if (tareas.Exists(t => t.Descripcion.Equals(descripcion, StringComparison.OrdinalIgnoreCase)))
                {
                    Console.WriteLine("Ya existe una tarea con esa descripción.");
                    continue;
                }

                tareas.Add(new Tarea(descripcion));
                break;
            }
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