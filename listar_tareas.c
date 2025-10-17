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
        bool salir = false;

        while (!salir)
        {
            Console.Clear();
            Console.WriteLine("GESTOR DE TAREAS");
            Console.WriteLine("1. Agregar nueva tarea");
            Console.WriteLine("2. Listar tareas pendientes");
            Console.WriteLine("3. Listar tareas completadas");
            Console.WriteLine("4. Marcar tarea como completada");
            Console.WriteLine("5. Eliminar tarea");
            Console.WriteLine("6. Salir");
            Console.Write("\nSelecciona una opción: ");

            string opcion = Console.ReadLine();

            switch (opcion)
            {
                case "1":
                    AgregarTarea();
                    break;
                case "2":
                    ListarTareas(false);
                    break;
                case "3":
                    ListarTareas(true);
                    break;
                case "4":
                    MarcarComoCompletada();
                    break;
                case "5":
                    EliminarTarea();
                    break;
                case "6":
                    salir = true;
                    Console.WriteLine("Hasta luego");
                    break;
                default:
                    Console.WriteLine("Opción inválida");
                    Console.ReadKey();
                    break;
            }
        }
    }

    static void AgregarTarea()
    {
        Console.Clear();
        Console.Write("Escribe la descripción de la nueva tarea: ");
        string descripcion = Console.ReadLine();

        if (!string.IsNullOrWhiteSpace(descripcion))
        {
            tareas.Add(new Tarea(descripcion));
            Console.WriteLine("Tarea agregada correctamente.");
        }
        else
        {
            Console.WriteLine("La descripción no puede estar vacía.");
        }

        Console.ReadKey();
    }

    static void ListarTareas(bool completadas)
    {
        Console.Clear();
        Console.WriteLine(completadas ? "TAREAS COMPLETADAS:\n" : "TAREAS PENDIENTES:\n");

        int contador = 0;
        for (int i = 0; i < tareas.Count; i++)
        {
            if (tareas[i].Completada == completadas)
            {
                contador++;
                Console.WriteLine($"{contador}. {tareas[i].Descripcion}");
            }
        }

        if (contador == 0)
        {
            Console.WriteLine("No hay tareas en esta categoría.");
        }

        Console.ReadKey();
    }

    static void MarcarComoCompletada()
    {
        Console.Clear();
        Console.WriteLine("TAREAS PENDIENTES:\n");

        List<int> indices = new List<int>();
        for (int i = 0; i < tareas.Count; i++)
        {
            if (!tareas[i].Completada)
            {
                indices.Add(i);
                Console.WriteLine($"{indices.Count}. {tareas[i].Descripcion}");
            }
        }

        if (indices.Count == 0)
        {
            Console.WriteLine("No hay tareas pendientes.");
            Console.ReadKey();
            return;
        }

        Console.Write("Selecciona el número de la tarea a marcar como completada: ");
        if (int.TryParse(Console.ReadLine(), out int seleccion) && seleccion > 0 && seleccion <= indices.Count)
        {
            tareas[indices[seleccion - 1]].Completada = true;
            Console.WriteLine("Tarea marcada como completada.");
        }
        else
        {
            Console.WriteLine("Selección inválida.");
        }

        Console.ReadKey();
    }

    static void EliminarTarea()
    {
        Console.Clear();
        Console.WriteLine("TAREAS REGISTRADAS:\n");

        for (int i = 0; i < tareas.Count; i++)
        {
            Console.WriteLine($"{i + 1}. {tareas[i].Descripcion} [{(tareas[i].Completada ? "Completada" : "Pendiente")}]");
        }

        if (tareas.Count == 0)
        {
            Console.WriteLine("No hay tareas para eliminar.");
            Console.ReadKey();
            return;
        }

        Console.Write("Selecciona el número de la tarea a eliminar: ");
        if (int.TryParse(Console.ReadLine(), out int seleccion) && seleccion > 0 && seleccion <= tareas.Count)
        {
            tareas.RemoveAt(seleccion - 1);
            Console.WriteLine("Tarea eliminada correctamente.");
        }
        else
        {
            Console.WriteLine("Selección inválida.");
        }

        Console.ReadKey();
    }
}