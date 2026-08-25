
-- Завдання 2.1: Створення таблиці ігор
CREATE TABLE games (
    id SERIAL PRIMARY KEY,
    title VARCHAR(100) NOT NULL UNIQUE,
    genre VARCHAR(50) NOT NULL,
    release_year INTEGER,
    rating DECIMAL(3, 1) CHECK (rating >= 0 AND rating <= 10)
);

-- Завдання 2.2: Створення таблиці ігрових сесій
CREATE TABLE game_sessions (
    id SERIAL PRIMARY KEY,
    player_id INTEGER NOT NULL,
    game_id INTEGER NOT NULL,
    started_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    duration_minutes INTEGER CHECK (duration_minutes > 0),
    score INTEGER DEFAULT 0
);

-- Завдання 2.3: Додавання тестових даних
INSERT INTO games (title, genre, release_year, rating)
VALUES
    ('Cyber Quest', 'Action', 2023, 8.5),
    ('Dragon Realms', 'RPG', 2024, 9.2);

INSERT INTO game_sessions (player_id, game_id, duration_minutes, score)
VALUES (1, 1, 45, 1500);

-- Перевірте результати:
SELECT * FROM games;
SELECT * FROM game_sessions;



-- Індивідуальні завдання 
--  1. Ігри для додавання
INSERT INTO games (title, genre, release_year, rating)
VALUES
    ('Dead Signal', 'Horror', 2021, 5.2),
    ('Crimson Manor', 'Horror', 2018, 8.8),
    ('Night Terrors', 'Horror', 2025, 7.3),
    ('The Hollow', 'Horror', 2018, 9.6),
    ('Phantom Depths', 'Horror', 2025, 6.1);

--  2. Ігрові сесії
INSERT INTO game_sessions (player_id, game_id, duration_minutes, score)
VALUES
    (2, 3, 21, 143),
    (3, 4, 28, 437),
    (4, 5, 31, 315),
    (5, 6, 20, 426),
    (6, 7, 21, 326);


-- 3  Додаткове завдання
-- Створити таблицю achievements з колонками: 
-- id (SERIAL PRIMARY KEY), game_id (INTEGER, зовнішній ключ на games), 
-- title (VARCHAR(100) NOT NULL), description (TEXT)

create table achievements(
    id serial primary key,
    game_id int foreign key (game_id) references games (id)
    title varchar(100) not null,
    description text
);








SELECT * FROM games;
SELECT * FROM game_sessions;


-- Згадав як писати мультитабличні запити, (трохи прояснилось в голові)
select 
--    gs.id, 
    p.username as "Нікнейм", 
    g.title as "Гра", 
    g.genre as "Жанр",
    gs.duration_minutes as "Ігровий час", 
    gs.score as "Рахунок"
from 
    game_sessions as gs, 
    players as p, 
    games g 
where gs.player_id = p.id
and gs.game_id = g.id;




    





