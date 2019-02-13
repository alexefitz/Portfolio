/*
 * Name: Alex Fitzmaurice, Xander Hacking, Lura Rider, Jacob Winslow, Eli Monnig
 * Date: 1.15.2019
 * Description: Hangman Game
 */

import java.util.Random;
import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;

public class Hangman
{
    private static final Random randomNumbers = new Random();
    
    private enum Category {ANIMALS, DND, CARS, BOOKS, DESTINY };  //enum statuses for word category
    
    private static String[] animals = new String[]{"octopus", "dolphin", "elephant", "giraffe", "lynx", "hamster", "goldfish", "scorpion", "scarab", "antellop"};
    //all possible words in animal category
    
    private static String[] dnd = new String[]{"alchemist", "gold", "dragon", "dungeon", "human", "fighter", "warlock", "owlbear", "goblin", "kobold"};
    //all possible words in D&D category
    
    private static String[] cars = new String[]{"corvette", "rollsroyce", "porsche", "ferrari", "lamborghini", "fiat", "mercedes", "bugatti", "audi", "BMW"};
    //all possible words in cars category
    
    private static String[] books = new String[]{"hardback", "paperback", "ink", "paper", "frankenstein", "spines", "hobbit", "gatsby", "editor", "hamlet"};
    //all possible words in books category
    
    private static String[] destiny = new String[]{"hunter", "titan", "warlock", "malfeasance", "bygones", "riskrunner", "izanami", "bergusia", "volundr", "gofannon"};
    //all possible words in Destiny category
    
    public static void main(String[] args)
    {
        System.out.print('\u000C'); //clears screen of previous input
        
        Scanner input = new Scanner(System.in);  //Scanner class variable
        System.out.println("Please enter your name: ");
        String name = input.next();  //asks user for name and stores it in variable
        
        int wins = 0;
        int losses = 0;
        while(true)
        {
            System.out.print('\u000C');  //clears screen every loop
            
            ArrayList<String> wrongGuesses = new ArrayList<String>();  //Basically a vector of incorrect guesses
            Category cat;      //enum status variable
            String secretWord = "";  //random word variable
            int incorrect = 0; //number of incorrect guesses  
            String catName = ""; //string that holds category name
            
            //asks user what category of words they would like to guess from
            System.out.println(name + ", please select a category from the list: ");
            System.out.println("1. Animals");
            System.out.println("2. D&D");
            System.out.println("3. Cars");
            System.out.println("4. Books");
            System.out.println("5. Destiny");
            System.out.println("6. Random Category");
            System.out.println("0. Exit");
            int choice = input.nextInt();
            
            //switch that chooses a case based on what category user inputs
            switch(choice)
            {
                case 1:  
                {
                    cat = Category.ANIMALS;
                    secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                    catName = "Animals";
                    break;
                } //end case 1
                case 2:
                {
                    cat = Category.DND;
                    secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                    catName = "Dungeons and Dragons";
                    break;
                } //end case 2
                case 3:
                {
                    cat = Category.CARS;
                    secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                    catName = "Cars";
                    break;
                } //end case 3
                case 4:
                {
                    cat = Category.BOOKS;
                    secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                    catName = "Books";
                    break;
                } //end case 4
                case 5:
                {
                    cat = Category.DESTINY;
                    secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                    catName = "Destiny";
                    break;
                } //end case 5
                case 6: 
                {
                    switch(randomNumbers.nextInt(4) + 1) //switch that picks a random case
                    {
                        case 1:  default:
                        {
                            cat = Category.ANIMALS;
                            secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                            catName = "Animals";
                            break;
                        } //end case 1
                        case 2:
                        {
                            cat = Category.DND;
                            secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                            catName = "Dungeons and Dragons";
                            break;
                        } //end case 2
                        case 3:
                        {
                            cat = Category.CARS;
                            secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                            catName = "Cars";
                            break;
                        } //end case 3
                        case 4:
                        {
                            cat = Category.BOOKS;
                            secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                            catName = "Books";
                            break;
                        } //end case 4
                        case 5:
                        {
                            cat = Category.DESTINY;
                            secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                            catName = "Destiny";
                            break;
                        } //end case 5
                    }
                    break;
                }
                default:
                {
                    cat = Category.ANIMALS;
                    System.exit(0);
                } //end default case
            }
            
            
            char[] wordCharArray = secretWord.toCharArray(); //secret word as a char array, to be disregarded
            String[] wordArray = new String[secretWord.length()]; //String array, to hold wordCharArray, but in Strings
            for(int i = 0; i < wordArray.length; i++)
            {
                wordArray[i] = String.valueOf(wordCharArray[i]);  //converts wordCharArray into Strings
            }
            
            boolean[] isGuessed = new boolean[secretWord.length()]; //array for if the letter that is a part of the word has been guesed
            boolean complete = false; //if the game is complete either won or lost
            boolean fail = false; //if the game was lost
            for(boolean b: isGuessed)
            {
                b = false;  //each item in isGuessed is false
            }
            
            while(!complete) //while secret word isn't completely guessed
            {
                complete = true; //sets complete to true each time the while loops, to be changed later in the loop
                makeGallows(incorrect, catName);   //makes the gallows based on how many incorrect guesses
                System.out.println("Wrong guesses: ");
                for(int i = 0; i < incorrect; i++)
                {
                    System.out.print(wrongGuesses.get(i)); //prints all wrong guesses
                    System.out.print(" ");
                }
                System.out.println();
                
                for(int i = 0; i < secretWord.length(); i++)
                {
                    if(isGuessed[i])
                    {
                        System.out.print(wordArray[i] + " "); //if this character has been guessed, display it
                    }
                    else
                    {
                        System.out.print("_ "); //else, display a blank space
                    }
                }
                System.out.println();
                
                String guess = "  "; 
                while(guess.length() > 1)
                {
                    System.out.println(name + ", please enter a single-character guess.");  //asks user for a guess
                    guess = input.next();
                }
                guess = guess.toLowerCase(); //changes user input to all lowercase
                
                boolean right = false; //boolean to check if user input is valid answer
                for(int i = 0; i < wordArray.length; i++)
                {
                    if(guess.equals(wordArray[i]))  //if user input is any of the characters in secret word
                    {
                        isGuessed[i] = true;
                        right = true;
                    }
                }
                
                if (!right) //if user input was none of the characters in secret word
                {
                    if(!wrongGuesses.contains(guess)) //if list of incorrect guesses does not contain user input
                    {
                        wrongGuesses.add(guess);
                        incorrect++;
                    }
                }
                
                for(boolean t: isGuessed) //for each item in isGuessed array
                {
                    if(!t) //if any character in secret word has not been guessed, run input loop again
                    {
                        complete = false;
                    }
                }
                
                if(incorrect >= 6) //if user made the man hang, trigger fail sequence
                {
                    complete = true;
                    fail = true;
                }
            }
            makeGallows(incorrect, catName); //make the hangman picture
            System.out.println("Wrong guesses: ");
            for(int i = 0; i < incorrect; i++)
            {
                System.out.print(wrongGuesses.get(i)); //prints out all wrong guesses
                System.out.print(" ");
            }
            System.out.println();
            
            for(int i = 0; i < secretWord.length(); i++) //for loop that prints out completed word
            {
                if(isGuessed[i])
                {
                    System.out.print(wordArray[i] + " ");
                }
                else
                {
                    System.out.print("_ ");
                }
                
            }
            System.out.println();
            
            if(fail) //if user lost the game, print You Lose and increment lose counter
            {
                System.out.println("You Lose");
                losses++;
            }
            else //else, print You Win and increment win counter
            {
                System.out.println("You Win!");
                wins++;
            }
            
            System.out.println("You have won " + wins + " game(s) and lost " + losses + " game(s)"); //print stats of player
            System.out.println("Word: " + secretWord);
            System.out.println();
            System.out.println(name + ", Would you like to play again? (Yes or No)"); //asks if user would like to play again
            String answer = input.next();
            answer = answer.toLowerCase();
            if(answer.equals("no"))
            {
                System.exit(0); //if user does not want to play again, exit program
            }
        }
    }
    
    //uses randomNumbers variable to get a random word based on category
    public static String getWord(Category cat)
    {
        String output = ""; //output return string
        if(cat == Category.ANIMALS)
        {
            output = animals[randomNumbers.nextInt(9)]; //chooses random word from animals category
        }
        else if(cat == Category.DND)
        {
            output = dnd[randomNumbers.nextInt(9)]; //chooses random word from D&D category
        }
        else if(cat == Category.CARS)
        {
            output = cars[randomNumbers.nextInt(9)]; //chooses random word from cars category
        }
        else if(cat == Category.BOOKS)
        {
            output = books[randomNumbers.nextInt(9)]; //chooses random word from books category
        }
        else if(cat == Category.DESTINY)
        {
            output = destiny[randomNumbers.nextInt(9)]; //chooses random word from Destiny category
        }
        return output;
    }
    
    //creates hangman picture based on incorrect answers. 
    public static void makeGallows(int incorrect, String catName) 
    {
        System.out.print('\u000C'); //clears screen of previous input
        System.out.println("Category: " + catName);
        System.out.println();
        System.out.println("_______");
        System.out.println("|     |");
        if(incorrect >= 1) 
        {
            System.out.println("|     0");
            if(incorrect == 2)
            {
                System.out.println("|     |");
                System.out.println("|      ");
            }
            else if(incorrect == 3)
            {
                System.out.println("|     |\\");
                System.out.println("|       ");
            }
            else if(incorrect >= 4)
            {
                System.out.println("|    /|\\");
                if (incorrect == 5)
                {
                    System.out.println("|      \\");
                }
                else if (incorrect == 6)
                {
                    System.out.println("|    / \\");
                }
                else
                {
                    System.out.println("|      ");
                }
            }
            System.out.println("|      ");
            System.out.println("|       ");
        }
        else
        {
            System.out.println("|       ");
            System.out.println("|       ");
            System.out.println("|       ");
        }
        System.out.println("|       ");
        System.out.println("|       ");
        System.out.println();
    }
}