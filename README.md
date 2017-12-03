# Duplicate Remover
A program that removes duplicate letters from an array.

## Setup
1. Download and install [Git](https://git-scm.com/downloads), if you don't already have it.

2. Open terminal and run the git clone command:

   ```
   $ https://github.com/cramaechi/duplicate-remover.git
   ```
    or [download as ZIP](https://github.com/cramaechi/duplicate-remover/archive/master.zip).

3. Go to the project folder:

   ```
   $ cd duplicate-remover
   ```

4. Compile:

   ```
   $ make
   ```
   
## Usage
Run:

```
$ ./duplicate_remover
```

Sample Output:
```
Enter up to 19 letters: a b d e g a c g e g g e c a k                                                                 
a b d e g c k

Enter up to 19 letters: d g e c g a e g A B d E g a e G C E g                                                         
d g e c a B

Enter up to 19 letters: d g e c a g e k e i a c q k c D E H D A B                                                     
d g e c a k i q H B  
```
