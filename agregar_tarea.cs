using System;
using System.Collections.Generic;

namespace ListaDeTareas
{
    internal class Program
    {
        static List<string> tareas = new List<string>();

        static void Main(string[] args)
        {
            int opcion;
            do
            {
                Console.Clear();
                Console.WriteLine("=== Lista de Tareas ===");
                Console.WriteLine("1. Agregar tarea");
                Console.WriteLine("2. Ver tareas");
                Console.WriteLine("3. Salir");
                Console.Write("Elige una opción: ");
                opcion = int.Parse(Console.ReadLine());

                switch (opcion)
                {
                    case 1:
                        AgregarTarea();
                        break;
                    case 2:
                        VerTareas();
                        break;
                }

            } while (opcion != 3);
        }

        static void AgregarTarea()
        {
            Console.Write("Escribe la nueva tarea: ");
            string tarea = Console.ReadLine();
            tareas.Add(tarea);
            Console.WriteLine("Tarea agregada con éxito.");
            Console.WriteLine("Presiona una tecla para continuar...");
            Console.ReadKey();
        }

        static void VerTareas()
        {
            Console.WriteLine("\n--- Lista de Tareas ---");
            if (tareas.Count == 0)
                Console.WriteLine("No hay tareas registradas.");
            else
                for (int i = 0; i < tareas.Count; i++)
                    Console.WriteLine($"{i + 1}. {tareas[i]}");

            Console.WriteLine("\nPresiona una tecla para continuar...");
            Console.ReadKey();
        }
    }
}
