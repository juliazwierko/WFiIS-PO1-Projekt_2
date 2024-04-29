import matplotlib.pyplot as plt

# Dane wejściowe
students = ["Julia", "Sebastian", "Nowy student"]
math_grades = [[5, 5], [5, 4], []]
cpp_grades = [[4.5, 5], [0, 2], []]

# Obliczenie średnich ocen
math_avg = [sum(grades) / len(grades) if grades else None for grades in math_grades]
cpp_avg = [sum(grades) / len(grades) if grades else None for grades in cpp_grades]

# Tworzenie wykresu
plt.figure(figsize=(10, 6))

# Dodanie średnich ocen na wykres
plt.plot(students, math_avg, marker='o', label='Math')
plt.plot(students, cpp_avg, marker='o', label='C++')

# Dodanie etykiet osi
plt.xlabel('Student')
plt.ylabel('Average Grade')
plt.title('Average Grades for Students')
plt.ylim(0, 5)  # Ograniczenie zakresu osi y od 0 do 5

# Dodanie legendy
plt.legend()

# Zapis wykresu do pliku
plt.savefig('statystyki.png')

# Wyświetlenie wykresu
#plt.show()
