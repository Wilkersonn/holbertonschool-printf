<!-- PROJECT SHIELDS -->
<div align="center">

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]

</div>

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/Wilkersonn/holbertonschool-printf">
    <img src="https://cdn.prod.website-files.com/6105315644a26f77912a1ada/63eea844ae4e3022154e2878_Holberton.png" 
     alt="Logo" 
     style="width: 750px; height: 130px; margin-right: 20px;">
  </a>

<h3 align="center" style="color: #FF0000;">Holberton _printf</h3>

  <p align="center" style="color: #FF0000;">
    This project, undertaken for Holberton School, involves creating our own implementation of the `printf` function in C. The goal is to replicate `printf` functionality to gain a deeper understanding of formatting and handling variadic arguments.
    <br />
    <a href="https://github.com/github_username/repo_name"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/github_username/repo_name">View Demo</a>
    ·
    <a href="https://github.com/Wilkersonn/holbertonschool-printf/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    ·
    <a href="https://github.com/Wilkersonn/holbertonschool-printf/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
  </p>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary style="color: #FF0000;">Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project" style="color: #FF0000;">About The Project</a>
      <ul>
        <li><a href="#built-with" style="color: #FF0000;">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started" style="color: #FF0000;">Getting Started</a>
      <ul>
        <li><a href="#prerequisites" style="color: #FF0000;">Prerequisites</a></li>
        <li><a href="#installation" style="color: #FF0000;">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage" style="color: #FF0000;">Usage</a></li>
    <li><a href="#roadmap" style="color: #FF0000;">Roadmap</a></li>
    <li><a href="#contributing" style="color: #FF0000;">Contributing</a></li>
    <li><a href="#license" style="color: #FF0000;">License</a></li>
    <li><a href="#contact" style="color: #FF0000;">Contact</a></li>
    <li><a href="#acknowledgments" style="color: #FF0000;">Acknowledgments</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project

This project was developed by two Holberton School students, Zoyh and Wilkerson.

<p align="right">(<a href="#readme-top" style="color: #FF0000;">back to top</a>)</p>

### Built With

* [![Next][Next.js]][Next-url]

<p align="right">(<a href="#readme-top" style="color: #FF0000;">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

Before you begin, we recommend that you:

1. **Read the Documentation**: Familiarize yourself with the project's documentation to understand its features and requirements.
2. **Review the README**: read the README.md file for an overview of the project and setup instructions.
3. **Ensure GCC is Installed**: Make sure you have GCC (GNU Compiler Collection) installed on your system for compiling the code.

### Installation

1. Make sure to ⭐ the project! (Just kidding, but it would be cool 😎)
2. Clone the repo
   ```sh
   git clone https://github.com/Wilkersonn/holbertonschool-printf.git
   ```
3. Navigate to the project directory!
   ```sh
   cd holbertonschool-printf
   ```
4. Go check the "exemple.c" to see how the _printf function can be use !

<p align="right">(<a href="#readme-top" style="color: #FF0000;">back to top</a>)</p>

<!-- USAGE EXAMPLES -->
## Usage

In this section, you'll find various examples demonstrating how to use `_printf`. This includes code snippets, screenshots, and demos to help illustrate different use cases and functionalities of the `_printf` implementation. For more detailed examples and additional resources, feel free to explore the links provided.

//NOT FINISH, IN BUILD\\

<p align="right">(<a href="#readme-top" style="color: #FF0000;">back to top</a>)</p>

<!-- ROADMAP -->
## FlowChart

```
┌─────────────────┐
│      Start      │
└────────┬────────┘
         │
         ▼
┌─────────────────┐    Yes   ┌─────────────────┐
│  format == NULL?├─────────►│   Return -1     │
└────────┬────────┘          └─────────────────┘
         │ No
         ▼
┌─────────────────┐
│ Initialize      │
│ va_list & count │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│  Loop through   │
│  format string  │◄─────────────────────────┐
└────────┬────────┘                          │
         │                                   │
         ▼                                   │
┌─────────────────┐   Yes   ┌───────────────┐│
│ Is char '%'?    ├────────►│ Next char '\0'?│
└────────┬────────┘         └───────┬───────┘│
         │ No                      │ No      │
         │                         ▼         │
         │                 ┌───────────────┐ │
         │                 │ Check specifier│ │
         │                 └───────┬───────┘ │
         │                         │         │
         │           ┌─────────────┴───────┐ │
         │           ▼             ▼       ▼ │
         │    ┌──────────┐  ┌──────────┐ ┌──────────┐
         │    │    %c    │  │   %s     │ │  %d/%i   │
         │    └────┬─────┘  └────┬─────┘ └────┬─────┘
         │         │            │           │
         │         ▼            ▼           ▼
         │    ┌──────────┐  ┌──────────┐ ┌──────────┐
         │    │print_char│  │print_str │ │print_int │
         │    └────┬─────┘  └────┬─────┘ └────┬─────┘
         │         │            │           │
         │         └────────────┴───────────┘
         │                     │
         ▼                     │
┌─────────────────┐            │
│  Print char &   │            │
│ increment count │            │
└────────┬────────┘            │
         │◄───────────────────┐│
         │                    ││
         ▼                    ││
┌─────────────────┐    No     ││
│   End of format ├───────────┘│
│     string?     │            │
└────────┬────────┘            │
         │ Yes                 │
         ▼                     │
┌─────────────────┐            │
│   End va_list   │            │
└────────┬────────┘            │
         │                     │
         ▼                     │
┌─────────────────┐            │
│  Return count   │            │
└────────┬────────┘            │
         │                     │
         ▼                     │
┌─────────────────┐            │
│      End        │            │
└─────────────────┘            │
```

<p align="right">(<a href="#readme-top" style="color: #FF0000;">back to top</a>)</p>

<!-- CONTRIBUTING -->
## Contributor

- **Wilkersonn** - Primary contributor
- **ZoyKh4** - Secondary contributor

## Contributor Activities

### Wilkersonn
<img src="https://github-readme-activity-graph.vercel.app/graph?username=Wilkersonn&bg_color=011627&color=79d3c3&line=c792ea&point=ffeb95&area=true&hide_border=false" width="50%" />

### ZoyKh4
<img src="https://github-readme-activity-graph.vercel.app/graph?username=ZoyKh4&bg_color=011627&color=79d3c3&line=c792ea&point=ffeb95&area=true&hide_border=false" width="50%" />

<p align="right">(<a href="#readme-top" style="color: #FF0000;">back to top</a>)</p>

<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top" style="color: #FF0000;">back to top</a>)</p>

<!-- CONTACT -->
## Contact

Feel free to add me on Discord: wilkersondereretour

<p align="right">(<a href="#readme-top" style="color: #FF0000;">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
[contributors-shield]: https://img.shields.io/github/contributors/Wilkersonn/holbertonschool-printf.svg?style=for-the-badge
[contributors-url]: https://github.com/Wilkersonn/holbertonschool-printf/graphs/contributors

[forks-shield]: https://img.shields.io/github/forks/Wilkersonn/holbertonschool-printf.svg?style=for-the-badge
[forks-url]: https://github.com/Wilkersonn/holbertonschool-printf/network/members

[stars-shield]: https://img.shields.io/github/stars/Wilkersonn/holbertonschool-printf.svg?style=for-the-badge
[stars-url]: https://github.com/Wilkersonn/holbertonschool-printf/stargazers

[issues-shield]: https://img.shields.io/github/issues/Wilkersonn/holbertonschool-printf.svg?style=for-the-badge
[issues-url]: https://github.com/Wilkersonn/holbertonschool-printf/issues

[license-shield]: https://img.shields.io/github/license/Wilkersonn/holbertonschool-printf.svg?style=for-the-badge
[license-url]: https://github.com/Wilkersonn/holbertonschool-printf/blob/master/LICENSE.txt

[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/linkedin_username
[product-screenshot]: images/screenshot.png
[Next.js]: https://img.shields.io/badge/C%20language-A8B9CC?style=for-the-badge&logo=c&logoColor=white
[Next-url]: https://www.gnu.org/software/gnu-c-manual/
