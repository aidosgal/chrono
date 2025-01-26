# **Chrono | CLI Typing Test**

Chrono is a command-line typing test game that helps you improve your typing speed and accuracy. Test your skills in a fun and engaging way by typing various passages and receiving your results instantly.

## **Features**

- Test your typing speed in words per minute (WPM).
- Measure your accuracy in typing.
- Typing passages are provided based on different difficulty levels.
- Display real-time typing feedback in the terminal.
- Clear results with WPM and accuracy percentage.

---

## **Installation & Setup**

To install and run Chrono, follow these steps:

### **Prerequisites**

- **C Compiler**: Ensure you have a working C compiler such as `gcc`.
- **Make**: Ensure you have `make` installed on your system.

### **Install Chrono**

1. Clone the repository or navigate to the Chrono project directory in the terminal.
   
2. Run the following command to build and install the game:
   ```bash
   sudo make install
   ```

   This will compile the source code and install the executable into a global path (usually `/usr/local/bin/`).

### **Run the Game**

After installation, simply run Chrono with the following command:
```bash
chrono
```

This will start the game, and you’ll be prompted to choose a difficulty level and how many words you want to type.

---

## **How to Play**

1. **Choose Difficulty Level**:  
   Upon starting the game, you’ll be presented with the following options:
   - **Easy**: Shorter and simpler passages.
   - **Medium**: Moderately challenging text.
   - **Hard**: Complex and longer passages.

2. **Select Number of Words**:  
   You can choose the number of words you want to type, up to a maximum of **60 words**. This helps tailor the game to your preferred difficulty and typing test length.

3. **Start Typing**:  
   Once the passage is displayed, type the text exactly as shown. The game will show you your progress in real-time, displaying the correctly typed text in gray and the remaining text as underscores.

4. **Results**:  
   After completing the test, you’ll be presented with your **Words Per Minute (WPM)** and **Accuracy** percentage.

---

## **Command Line Options**

You can run the game with additional options or use it in a script to automate certain aspects of the typing test. Below are the main command-line options available:

- **--help**: Displays the help information and command-line options.
  
  Example:
  ```bash
  chrono --help
  ```

---

## **Source Code and Contributions**

Feel free to fork this repository and contribute to the project! You can suggest improvements, report bugs, or even add new features. To contribute:

1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Submit a pull request for review.

---

## **License**

Chrono is open-source software licensed under the [MIT License](LICENSE).

---
