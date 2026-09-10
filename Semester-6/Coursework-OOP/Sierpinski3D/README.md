# Sierpinski3D — Real-Time 3D Raymarching Engine

Інтерактивна програма для візуалізації та дослідження 3D-тетраедра Серпінського у реальному часі.

---

## Технологічний стек

- **Мова:** C# (.NET 10.0)
- **Графічний API:** OpenGL 3.3 Core via **Silk.NET**
- **Шейдери:** GLSL
- **UI Framework:** **ImGui.NET**

---

## Швидкий запуск

### Вимоги
- [.NET 10.0 SDK](https://dotnet.microsoft.com/)
- Відеокарта з підтримкою **OpenGL 3.3** або вище

### Клонування та запуск

```bash
# Клонувати репозиторій
git clone https://github.com/ShadowWatcher543/MNTU-edu-archive.git

# Перейти в директорію проєкту
cd MNTU-edu-archive/Semester-6/Coursework-OOP/Sierpinski3D

# Зібрати та запустити проєкт
dotnet run
```

---

| Клавіші / Дія      | Функція                            |
| ------------------ | ---------------------------------- |
| **WASD**           | Переміщення камери у просторі      |
| **Space / Shift**  | Підйом / спуск камери              |
| **Рух миші**       | Огляд камери (Pitch / Yaw)         |
| **Коліщатко миші** | Зміна швидкості переміщення камери |
| **Left ALT**       | Перемикання між камерою та UI      |
| **ESC**            | Вихід із програми                  |


---

Sierpinski3D_Raymarching \
├── Core/             # Engine, WindowService, Program (Точка входу)\
├── Graphics/         # Shader, ScreenQuad (Низькорівнева робота з OpenGL)\
├── Scene/            # Camera, SierpinskiFractal, SceneEnvironment, Light, Skybox\
├── UI/               # UIManager, IUIWindow, модулі вікон ImGui\
└── Shaders/          # GLSL шейдери (vert_screen.glsl, frag_sierpinski.glsl)

---

Автор Паненко Ян (група аІк-43)  
Фаховий коледж ЗВО «Міжнародний науково-технічний університет імені академіка Юрія Бугая»



