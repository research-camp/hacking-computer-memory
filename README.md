<h1 align="center">
Hacking computer memory with C, But how?
</h1>

Access to other parts of memory with C programming language. How does C programming language allows us to
access every part of memory. How we can secure our system againts this problem?

## What is happening?

If you run the sample file with ```make run``` command, you can see that in this program we can access
memory parts out of array allocated space in memory.

```C
// let's see what happens if we update the 11th element.
memory[10] = 10;
```

The program will execute without any errors or warnings. Allow us to access any element out of array allocated space.
But how does this cause problems?

## Ideas

- Show the problems
- Give suggestions to fix or prevent the problem
- Tex file of research
