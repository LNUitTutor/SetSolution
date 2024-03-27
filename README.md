# Шаблон класу множина
## Інтерфейс
Множину можна створити:
- порожню
- з одного елемента
- з масиву елементів
- як копію іншої множини

Операції з множинами:
- додавання/вилучення елемента
- додавання масиву елементів
- об'єднання/перетин/різниця множин

Додаткові можливості:
- довідатися розмір множини
- вивести множину в потік

## Реалізація
Пам'ять множини утворює однозв'язний впорядкований список з заголовною ланкою. Збережено вказівник на заголовну ланку. Додатково зберігається кількість елементів списку.