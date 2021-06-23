<p align="center">
    <img alt="42-lyon" src="https://user-images.githubusercontent.com/45235527/106354618-6ec65a00-62f3-11eb-8688-ba9e0f4e77de.jpg" />
</p>

# Ft_printf

<img alt="Note" src="https://user-images.githubusercontent.com/45235527/96753610-698e7080-13d0-11eb-9461-d3351c9208d7.png" width="250" height="200" />

### <strong>Description</strong>

The versatility of the printf function in C represents a great exercise in programming for
us. This project is of moderate difficulty. It will enable you to discover variadic functions
in C.
The key to a successful ft_printf is a well-structured and good extensible code.


# Mandatory part

![Sujet](https://user-images.githubusercontent.com/45235527/96753783-a195b380-13d0-11eb-90f9-31928a4bc773.png)

- The prototype of ft_printf should be int ft_printf(const char *, ...);
- You have to recode the libc’s printf function
- It must not do the buffer management like the real printf
- It will manage the following conversions: cspdiuxX%
- It will manage any combination of the following flags: ’-0.*’ and minimum field
width with all conversions
- It will be compared with the real printf
- You must use the command ar to create your librairy, using the command libtool
is forbidden.
