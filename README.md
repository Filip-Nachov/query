<p align="center">

<img src="photos/query-banner.png">

</p>

<p align="center">

![Github Last Commit](https://img.shields.io/github/last-commit/Filip-Nachov/query)
![GitHub contributors](https://img.shields.io/github/contributors/Filip-Nachov/query)
![GitHub Created At](https://img.shields.io/github/created-at/Filip-Nachov/query)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/Filip-Nachov/query)
![GitHub License](https://img.shields.io/github/license/Filip-Nachov/query)

</p>

### ***A simple lightweight, C++ based terminal utility for searching text efficiently in Linux environments.***


## Installation and Build 🛠️
### Requirements:
- **Git:** For cloning the repository.
- **Make:** For building the project.
- **G++:** For compiling the C++ code. 

### Windows:
If you are using Windows, there are two methods to install this utility:

1. **Direct Installation on Windows Shells:**
- **Note:** This method is not recommended for beginners due to the complexities of configuring the `g++` compiler, Makefile, and environment paths on Windows.
- Steps:
    1. Install `g++`, `make`, and `git`.
    2. Clone the repository:
    ```
    git clone https://github.com/Filip-Nachov/query.git
    cd query
    make
    ```
    3. Add the `query` executable to your system's PATH.

2. **Using Windows Subsystem for Linux (WSL):**
    - **Recommended:** This method is easier and provides a Linux-like environment on Windows.
    - If WSL is already installed, follow the Linux/Mac instructions below.

### MacOS and Linux:
This method is straightforward and recommended. Ensure you have `git`, `make`, and `g++` installed. Then, run the following commands:
```
git clone https://github.com/Filip-Nachov/query.git
cd query
make
sudo make install
```

## Running the Utility 🏃‍♂️
### Example Usage:
To use the `query` utility, you'll need to pass a flag and a pattern as arguments. Here is an example:

```console
User@Github:~$ echo "Sample text with numbers 1234 and letters ABCD." | ./build/query -E "\\d"
```
### Explanation:
- `-E`: This flag indicates that a pattern is being provided.
- `\\d`: This pattern matches any digit.

### Expected Output:
If the input text contains any digits, the utility will print:
```console
Match
```

If no digits are found, it will print:
```console
Not Matching
```

## Contribution 🤗
Contributions are always welcome! To contribute:

1. Fork the repository.
2. Make your changes.
3. Create a Pull Request (PR) and provide a detailed explanation of your changes.

If the instructions aren't met, the PR may be rejected or you'll be asked to make changes. If you find a bug or have a feature request but don't want to code it, please create an issue. Thank you in advance!

## License 📜
This project is under the [MIT license](LICENSE).

## Check out my other projects 🚀
Take a look at my other projects and my GitHub profile:
- [My profile](https://github.com/Filip-Nachov)
- [My repositories](https://github.com/Filip-Nachov?tab=repositories)
