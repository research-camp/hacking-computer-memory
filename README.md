<h1 align="center">
Hacking computer memory with C, But how? (Buffer Overflow Attack)
</h1>

Access to other parts of memory with C programming language. How does C programming language allows us to
access every part of memory? How we can secure our system againts this problem?

In this research we are going to talk about **Buffer Overflow** and it is a common cause of security vulnerabilities, as not checking the bounds of an array before indexing it can result in malicious modifications to your program at runtime.

## What is happening actually?

Lets see the problem in an example. <br />
If you run the sample file with ```make run``` command, you can see that in this program we can access
memory parts out of array allocated space in memory.

```C
// let's see what happens if we update the 11th element.
#include <stdio.h>

int main() {
  // creating an array of size 10.
  int memory[10];

  // now trying to access the 11th element.
  printf("%d\n", memory[10]);

  // let's see what happens if we update the 11th element.
  memory[10] = 10;

  // let's see what happens if we access the 11th element again.
  printf("%d\n", memory[10]);

  return 0; 
}
```

The program will execute without any errors or warnings. Allow us to access any element out of array allocated space.
But how does this cause problems?

## Consequences

This access may subtly corrupt other memory used by your program, or may cause an immediate segmentation fault
depending on how that particular array is laid out in memory. **Buffer Overflows** can affect all types of software. They typically result from malformed inputs or failure to allocate enough space for the buffer.
If the transaction overwrites executable code, it can cause the program to behave unpredictably and generate incorrect results, memory access errors, or crashes.
It can also cause **Buffer Overflow attack**.

### Buffer Overflow Attack

In a **Buffer Overflow attack**, the extra data sometimes holds specific instructions for actions intended by a hacker or malicious user; for example, the data could trigger a response that damages files, changes data or unveils private information.

Attackers exploit **Buffer Overflow** issues by overwriting the memory of an application. This changes the execution path of the program, triggering a response that damages files or exposes private information. For example, an attacker may introduce extra code, sending new instructions to the application to gain access to IT systems.

If attackers know the memory layout of a program, they can intentionally feed input that the buffer cannot store, and overwrite areas that hold executable code, replacing it with their own code. For example, an attacker can overwrite a pointer (an object that points to another area in memory) and point it to an exploit payload, to gain control over the program.

### Types of Buffer Overflow Attacks

**Stack-based** buffer overflows are more common, and leverage stack memory that only exists during the execution time of a function.

**Heap-based** attacks are harder to carry out and involve flooding the memory space allocated for a program beyond memory used for current runtime operations.

## Which programming languages are more vulnerable?

C and C++ are two languages that are highly susceptible to buffer overflow attacks, as they do not have built-in safeguards against overwriting or accessing data in their memory. Mac OSX, Windows, and Linux all use code written in C and C++.

Languages such as PERL, Java, JavaScript, and C# use built-in safety mechanisms that minimize the likelihood of buffer overflow.

## How to Prevent Buffer Overflows?

### Bound indexing

Since you didn't show any code the answer can only be a general one: _Stay inside the bounds of the array_. Apart from accessing at some wildly out of bounds position, one particular case is more common: If you have an array with a size of 10 then 10 isn't a valid index. Because arrays in C++ are 0-based. So in this case, valid indices are 0 to 9.

### Use dynamic lists

You must not go out of bounds, the C/C++ developer has to be precise. That said, you could use _std::vector_ instead of a plain array: it provides the _std::vector::at_ method that throws an exception if you try to make an out-of-bounds access.

### Address space randomization (ASLR)

Randomly moves around the address space locations of data regions. Typically, buffer overflow attacks need to know the locality of executable code, and randomizing address spaces makes this virtually impossible.

### Data execution prevention flags

These flags certain areas of memory as non-executable or executable, which stops an attack from running code in a non-executable region.

### Structured exception handler overwrite protection (SEHOP)

Helps stop malicious code from attacking Structured Exception Handling (SEH), a built-in system for managing hardware and software exceptions. It thus prevents an attacker from being able to make use of the SEH overwrite exploitation technique. 
At a functional level, an SEH overwrite is achieved using a stack-based buffer overflow to overwrite an exception registration record, stored on a thread’s stack.

Security measures in code and operating system protection are not enough. When an organization discovers a buffer overflow vulnerability, it must react quickly to patch the affected software and make sure that users of the software can access the patch.

## Resources

- [Stack Overflow question about Buffer Overflow](https://stackoverflow.com/questions/38416792/array-allows-out-of-bounds-access-in-c)
- [Avoid out of bounds array article](https://www.codeproject.com/Questions/1075908/what-you-do-to-avoid-out-of-bounds-array-access-in)
- [Imperva article about Buffer Overflow](https://www.imperva.com/learn/application-security/buffer-overflow/)
- [GeeksForGeeks](https://www.geeksforgeeks.org/buffer-overflow-attack-with-example/)
