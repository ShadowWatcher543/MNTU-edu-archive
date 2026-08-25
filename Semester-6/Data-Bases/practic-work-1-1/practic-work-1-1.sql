ALTER TABLE players ADD COLUMN rating DECIMAL(3,2) CHECK (rating >= 0 AND rating <= 5);



INSERT INTO players (username, level, rating)
VALUES
    ('ZeusThunder', 94, 1.5),
    ('OdinRaven', 80, 2.9),
    ('ThorHammer', 76, 1),
    ('LokiTrick', 96, 1.7),
    ('FreyaSword', 98, 4.5);	



insert into players (username, level, rating)
values ('YanPanenko', 42, 0.1)



SELECT * FROM players;
