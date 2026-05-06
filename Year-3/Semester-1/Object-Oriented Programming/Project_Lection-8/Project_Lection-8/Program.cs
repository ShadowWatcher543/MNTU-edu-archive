namespace Project_Lection_8;

class Program {
    
    static void Main(string[] args) {
        
        int[] numbers = new int[3];
        numbers[0] = 1;
        numbers[1] = 15;
        numbers[2] = 2;

        Console.WriteLine("--- Task 1 ---");
        Task1();

        Console.WriteLine("\n--- Task 2 ---");
        ShowAllElements(numbers);

        Console.WriteLine("\n--- Task 3 ---");
        ShowSumOfAllElements(numbers);

        Console.WriteLine("\n--- Task 4 ---");
        ShowCountOfElements(numbers);
        
    }

    private static void Task1() {
        string[] words = new string[5];
        words[0] = "Fabric";
        words[1] = "Wood";
        words[2] = "Water";
        words[3] = "Stone";
        words[4] = "Paper";
    }
    
    private static void ShowAllElements(int[] numbers) {
        foreach (var num in numbers) {
            Console.Write(num + " ");
        }
        Console.WriteLine();
    }

    private static void ShowSumOfAllElements(int[] numbers) {
        int sum = 0;
        
        foreach (var num in numbers) {
            sum += num;
        }
        
        Console.WriteLine($"Summ of array is {sum}");
    }
    
    private static void ShowCountOfElements(int[] numbers) {
        Console.WriteLine(numbers.Length);
    }
}