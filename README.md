<h1 align="center">Computer Science Capstone</h1>
<h2 align="center">Thy Tran</h2>

<table align="center" border="2" cellpadding="10" cellspacing="0">
  <tr>
    <td align="center">
      <b>Welcome to my Computer Science Capstone ePortfolio.</b>
    </td>
  </tr>
</table>

# Professional Self-Assessment

# Code Review
<a href="https://www.youtube.com/watch?v=XIoURJRoHtc" target="_blank"
style="display:inline-block;padding:10px 15px;background:#ff0000;color:white;text-decoration:none;border-radius:6px;font-weight:bold;">
▶ Watch Code Review Video
</a> 
  
# Enhancement One: Software Design and Engineering 
<img width="380" height="61" alt="Screenshot 2026-06-20 at 7 43 52 PM" src="https://github.com/user-attachments/assets/5326f7cd-8ea8-49c2-bad0-51155ccfa30f" />
<img width="421" height="72" alt="Screenshot 2026-06-20 at 7 43 45 PM" src="https://github.com/user-attachments/assets/c38a4ee8-c97d-454c-99e3-c354391182bc" />
<img width="343" height="61" alt="Screenshot 2026-06-20 at 7 42 44 PM" src="https://github.com/user-attachments/assets/88daadd5-df00-47e5-86c8-986ff2e6bb0b" />
<img width="495" height="88" alt="Screenshot 2026-06-20 at 7 42 20 PM" src="https://github.com/user-attachments/assets/8ff5312d-ab0c-4a24-9954-c6ae7b429e71" />

### Artifact

The artifact I selected is a C++ program developed last term in CS-405: Secure Coding titled Buffer Overflow Example. The program was originally created to demonstrate how unsafe memory handling using fixed-size character arrays can lead to buffer overflow vulnerabilities. It was developed during CS -05 as a learning exercise focused on identifying and understanding security weaknesses in low-level input handling. The original version used a fixed-size character array and std::cin.getline() to limit the input size while printing the constant account number that cannot be modified. 

### Inclusion

This artifact was selected for my ePortfolio because it clearly demonstrates not only a common security vulnerability and a meaningful opportunity for software improvement, but also fits the category of software design and engineering. It showcases my ability to analyze insecure code and apply secure software engineering practices to improve it. The enhanced version of the program demonstrates key development skills, including refactoring procedural code into modular functions, implementing input validation, and applying safer C++ constructs such as std::string. The artifact was improved by removing unsafe memory handling, restructuring the program into separate functions of getUserInput, validateInput, and displayOutput, while also improving maintainability, readability, and security. These changes demonstrate a transition from basic procedural programming to a structured software engineering approach emphasizing modularity and maintainability. 

### Course Outcomes

The enhancement met the planned course outcomes from Module One. Specifically, Outcome 3 (Design and evaluate computing solutions that solve a given problem using algorithmic principles and computer science practices and standards appropriate to its solution while managing the trade-offs involved in design choices) was addressed through improved software design and evaluation of trade-offs between raw memory handling and safer abstractions. Outcome 4 (Demonstrate an ability to use well-founded and innovative techniques, skills, and tools in computing practices for the purpose of implementing computer solutions that deliver value and accomplish industry-specific goals) was demonstrated using modular design and refactoring techniques to improve overall code structure and maintainability. Outcome 5 (Develop a security mindset that anticipates adversarial exploits in software architecture and designs to expose potential vulnerabilities, mitigate design flaws, and ensure privacy and enhanced security of data and resources) was achieved by identifying and mitigating a buffer overflow vulnerability through secure input handling and validation. While there are no major changes to my outcome-coverage plan at this moment, I plan on further strengthening Outcome 1 and 2 by improving documentation quality and presentation in my future portfolio artifacts. 

### Reflection

Through enhancing this artifact, I gained deeper knowledge about the importance of designing software with both functionality and security in mind. One of the main things that I learned was how one small design decision could significantly impact security and maintainability, such as using raw character arrays versus using std::string. A major challenge that I encountered while working on this enhancement was restructuring the original procedural logic into modular functions while also preserving the intended program behavior. This required careful planning of data flow between functions to ensure correctness. Overall, this enhancement process has strengthened my understanding of secure coding principles, modular design, and the importance of writing maintainable and professional-quality software. 

# Enhancement Two: Algorithms and Data Structure 

<img width="393" height="608" alt="Screenshot 2026-06-20 at 7 54 12 PM" src="https://github.com/user-attachments/assets/64efa612-b6b8-45a7-b71e-5621116432a1" />
<img width="444" height="868" alt="Screenshot 2026-06-20 at 7 55 19 PM" src="https://github.com/user-attachments/assets/54ad216e-62f8-40cb-8314-765efc584ccc" />

### Artifact
  The artifact I selected is a C++ program developed in CS 300: Data Structures and Algorithms titled *Course Planner*. The program was created to assist students and advisors by loading course information from a CSV file, storing course data using a hash table implemented with an unordered map, and allowing users to search for courses and view prerequisite information. The original version created in CS 300 primarily used vectors to store prerequisites and relied on basic lookup functionality within a hash table structure to retrieve course information.
  
### Inclusion

This artifact was selected for my ePortfolio because it demonstrates my ability to apply data structures and algorithmic principles to solve a real-world academic planning problem. It fits the Algorithms and Data Structures category by showcasing the use of a hash table for efficient data retrieval and an enhanced graph-based structure to better represent course prerequisite relationships. The enhanced version of the program demonstrates key algorithmic improvements, including the implementation of a graph representation using adjacency lists and the use of depth-first search (DFS) to traverse prerequisite chains. These improvements strengthened the overall design by providing a more accurate representation of course dependencies and enabling more meaningful analysis of each prerequisite pathway. In addition, the artifact demonstrates my ability to evaluate and improve existing code by integrating multiple data structures to enhance functionality and efficiency.
  
### Course Outcomes

This enhancement met the planned course outcomes from Module One, similarly to Enhancement One. Like Enhancement One, this enhancement also met outcome 3 (Design and evaluate computing solutions that solve a given problem using algorithmic principles and computer science practices and standards appropriate to its solution while managing the trade-offs involved in design choices), which was addressed through the implementation of both a hash table and a graph-based structure, allowing for efficient course lookup while also improving the representation of prerequisite relationships. Outcome 4 (Demonstrate an ability to use well-founded and innovative techniques, skills, and tools in computing practices for the purpose of implementing computer solutions that deliver value and accomplish industry-specific goals) was also demonstrated through the integration of multiple data structures and the implementation of depth-first search (DFS) to enhance overall program functionality. While the original system provided basic lookup capabilities, the enhancement introduced a more advanced algorithmic approach to analyzing course dependencies. Currently, there are no significant changes to my outcome-coverage plan, but I am still planning on strengthening Outcomes 1 and 2 by improving documentation quality and presentation in my future portfolio artifacts.

### Reflection

Through enhancing this artifact, I gained a deeper understanding of how different data structures can be combined to improve both functionality and design. One of the most important lessons I learned during this process was the value of representing real-world relationships using appropriate structures, such as graphs for prerequisite dependencies, rather than relying on linear storage in vectors alone. Implementing depth-first search (DFS) to traverse prerequisite chains helped me better understand how recursive algorithms can be used to explore connected data. A major challenge I encountered during this enhancement was ensuring that the graph-based representation worked correctly alongside the existing hash table structure without introducing redundancy or inconsistencies in the data. Debugging traversal logic and ensuring accurate course relationships required careful testing and validation of different input scenarios. Overall, this enhancement strengthened my understanding of algorithm design, graph structures, and the importance of selecting the most appropriate data structures to improve software design and functionality.


# Enhancement Three: Databases

<img width="1708" height="854" alt="Screenshot 2026-06-20 at 7 05 13 PM" src="https://github.com/user-attachments/assets/b12edd15-6a2e-45cd-a319-8c23361a9648" />
<img width="1710" height="591" alt="Screenshot 2026-06-20 at 7 05 39 PM" src="https://github.com/user-attachments/assets/668f66ec-77bb-44d6-97be-dc78599af18e" />

### Artifact

The artifact that I have selected is a database-driven interactive dashboard that I developed in CS 340: Client/Server Development. The Grazioso Salvare application was designed to assist users in analyzing animal shelter data using MongoDB. The system uses a custom CRUD Python module to manage database operations and supports dynamic filtering, data visualization, and geospatial mapping. The original version of this database artifact relied primarily on basic MongoDB queries and a simple Dash interface for displaying tabular data. 
  
### Inclusion

This artifact was selected because it demonstrates my ability to develop a full-stack, data-driven application that uses database integration, backend processing, and interactive visualization. The enhanced version of the Grazioso Salvare dashboard improves system reliability through a hybrid MongoDB and CSV fallback design, ensuring that the application continues to function even when the database is unavailable. Additional enhancements also include improved CRUD functionality with exception handling and input validation, as well as support for MongoDB-style query operators in the CSV fallback system. The dashboard was also enhanced with dynamic filtering, a Plotly pie chart for breed distribution, and a Dash Leaflet map for geolocation visualization. These improvements increased usability, flexibility, and overall robustness of the application. 
  
### Course Outcomes

This enhancement met the planned course outcomes identified in Module One. Outcome 3 (Design and evaluate computing solutions that solve a given problem using algorithmic principles and computer science practices and standards appropriate to its solution, while managing the trade-offs involved in design choices) was demonstrated through the development of MongoDB query structures that efficiently retrieve and filter rescue animal records based on the user-selected criteria. The enhancement required evaluating how data should be organized and retrieved to support dashboard functionality while maintaining performance and usability. Outcome 4 (Demonstrate an ability to use well-founded and innovative techniques, skills, and tools in computing practices for the purpose of implementing computer solutions that deliver value and accomplish industry-specific goals) was demonstrated with MongoDB, Python, Dash, and data visualization tools to create a more robust database-driven application. The implementation of CRUD functionality and interactive dashboard components strengthened the overall value and usability of the application. Outcome 5 (Develop a security mindset that anticipates adversarial exploits in software architecture and designs to expose potential vulnerabilities, mitigate design flaws, and ensure privacy and enhanced security of data and resources) was demonstrated through the implementation of validation checks and exception handling within the CRUD operations. Each addition improved the reliability of database interactions and helped prevent unexpected errors during data processing. There are no significant changes to my outcome-coverage plan; however, I plan to strengthen Outcomes 1 and 2 by improving technical communication and documentation through the development and publication of my ePortfolio. 
  
### Reflection

During this enhancement, I gained a greater understanding of how database design and system architecture influence application reliability and usability. Implementing a hybrid MongoDB and CSV fallback system helped me understand how real-world applications must be designed to remain functional even when primary services are unavailable. I also learned how to utilize pandas to simulate database query operations in fallback mode, which strengthened my overall understanding of data filtering and transformation. This required careful attention to maintaining consistent behavior between MongoDB and CSV data handling. The main challenge I encountered during this enhancement was ensuring that both MongoDB and CSV data sources returned consistent results within the dashboard. Debugging filtering logic and verifying correct data output required iterative testing and validation. Another challenge was handling potential errors such as missing or malformed data, which was addressed through input validation and exception handling in the CRUD module. Overall, this project improved my understanding of full-stack application development, database integration, and defensive programming best practices. It also strengthened my ability to design systems that are both functional and resilient.
