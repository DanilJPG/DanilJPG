## Part1. Установка ОС
- Проверка версии Ubuntu

![https://github.com/DanilJPG/images/blob/main/Рисунок1.png](https://github.com/DanilJPG/images/blob/main/Рисунок1.png)

## Part2. Создание пользователя
- Команда создания пользователя test добавление его в групппу adm

![Команда создания пользователя test добавление его в групппу adm](https://github.com/DanilJPG/images/blob/main/Рисунок2.png?raw=true)

- Вывод команды проверки пользователя test

![Вывод команды проверки пользователя test](https://github.com/DanilJPG/images/blob/main/Рисунок3.png?raw=true)
## Part3. Настройка сети ОС
1. Установи временную зону, соответствующую твоему текущему местоположению
- `sudo ln -sf /usr/share/zoneinfo/Europe/Moscow /etc/localtime`, `timedatectl`

2. Выведи названия сетевых интерфейсов с помощью консольной команды
   ![image](https://github.com/DanilJPG/images/blob/main/Рисунок4.png?raw=true)

- lo - сетевой интерфейс может быть виртуальным, который отвечает за сетевое общение программ операционной системы данной ВМ. lo – сетевой виртуальный интерфейс который используется по умолчанию в Linux. Он используется для отладки сетевых программ и запуска серверных приложений на локальной машине. С этим интерфейсом всегда связан адрес 127.0.0.1 и него есть dns – localhost. Привязка находится по адресу /etc/hosts. Используется самой системой для тестирования сетевых приложений без выхода в реальную сеть. Например, вы запускаете сервер и клиент на одном компьютере, они могут общаться через 127.0.0.1

3. Используя консольную команду, получи ip адрес устройства, на котором ты работаешь, от DHCP-сервера
- `ip route` используется для проверки маршрутов по передачи данных, `grep default` отображает значение шлюза через который будут оставлены пакеты по умолчанию

   ![image](https://github.com/DanilJPG/images/blob/main/Рисунок5.png?raw=true)

- DHCP –динамический протокол настройки хоста
4. Определи и выведи на экран внешний ip-адрес шлюза (ip) и внутренний IP-адрес шлюза, он же ip-адрес по умолчанию (gw)
- `ip addr show` или `ip a`

    ![image](https://github.com/DanilJPG/images/blob/main/Рисунок6.png?raw=true)
  
5. Задай статичные (заданные вручную, а не полученные от DHCP-сервера) настройки ip, gw, dns (используй публичный DNS-серверы, например 1.1.1.1 или 8.8.8.8).
- Для установки постояннх значений настроектребуется:
- изменить `config` файл, взависимости от системы(в etc/netplan)

    ![image](https://github.com/DanilJPG/images/blob/main/Рисунок7.png?raw=true)
    
- установить необходимые значения:

    ![image](https://github.com/DanilJPG/images/blob/main/Рисунок8.png?raw=true)
    
- убедится после перезагрузки в правильности:

    ![image](https://github.com/DanilJPG/images/blob/main/Рисунок9.png?raw=true)
  
- пинг удаленных хостов

     ![image](https://github.com/DanilJPG/images/blob/main/Рисунок10.png?raw=true)
## Part4. Обновление ОС
1. Обновление системных пакетов
   ![image](https://github.com/DanilJPG/images/blob/main/Рисунок11.png?raw=true)

## Part 5. Использование команды sudo
1. Добавление в группу sudo gпользователя test(для выполнения команд как root, предоставление прав su)
   ![image](https://github.com/DanilJPG/images/blob/main/Рисунок12.png?raw=true)
2. `sudo hostnamectl set-hostname новое_имя`

3. Проверка cat /etc/hostname
   
   ![image](https://github.com/DanilJPG/images/blob/main/Рисунок13.png?raw=true)

   
## Part 6. Установка и настройка службы времени
1. Проверка часового пояса и синхронизации
   
   ![image](https://github.com/DanilJPG/images/blob/main/Рисунок14.png?raw=true)

   ![image](https://github.com/DanilJPG/images/blob/main/Рисунок15.png?raw=true)


## Part 7. Установка и использование текстовых редакторов
1. Создание файлов и выход с сохранением из них
- Joe: `Ctrl+K+X`
   
   ![image](https://github.com/DanilJPG/images/blob/main/Рисунок16.png?raw=true)
   
- nano: `Ctrl+X+Y`
   
   ![image](https://github.com/DanilJPG/images/blob/main/Рисунок17.png?raw=true)
   
- Vim: `:wq`
   
   ![image](https://github.com/DanilJPG/images/blob/main/Рисунок18.png?raw=true)

2. Замена сожержимого файлов, выход без сохранения
- Joe: `Ctrl+K+Q+n`
   
   ![image](https://github.com/DanilJPG/images/blob/main/Рисунок19.png?raw=true)

- nano: `Ctrl+X+n`

   ![image](https://github.com/DanilJPG/images/blob/main/Рисунок20.png?raw=true)

- Vim: `:q!`

   ![image](https://github.com/DanilJPG/images/blob/main/Рисунок21.png?raw=true)

3. Функции поиска слова и его замена
- Joe:   `^K+F+ввод поискового слова+B`
         `^K+F+R+старое слово + новое слово+y`

   ![image](https://github.com/DanilJPG/images/blob/main/Рисунок22.png?raw=true)

   ![image](https://github.com/DanilJPG/images/blob/main/23.png?raw=true)

- nano: `^w+fets(слово для поиска)`
        `^\+fest(old name)+castaaa(new name+enter)+y`
  
  ![image](https://github.com/DanilJPG/images/blob/main/24.png?raw=true)

  ![image](https://github.com/DanilJPG/images/blob/main/25.png?raw=true)

  - Vim: `/lot(слово для описка)`
  `:%s/old_name/new_name/`
 
   ![image](https://github.com/DanilJPG/images/blob/main/26.png?raw=true)

   ![image](https://github.com/DanilJPG/images/blob/main/27.png?raw=true)

## Part 8. Установка и базовая настройка сервиса SSHD
1. `sudo apt install openssh-server` - установка openssh
2. `sudo systemctl enable ssh` - автозагрузка ssh
3. `sudo nano /etc/ssh/sshd_config` + изменение в конфиг-файле на port 2022
4. ps –ef | grep sshd

- Скрины с выводом команд

![image](https://github.com/DanilJPG/images/blob/main/Рисунок28.png?raw=true)

![image](https://github.com/DanilJPG/images/blob/main/Рисунок29.png?raw=true)

`-t показывает только tcp соединения` 
`-a показывает все соединения и порты, в том числе со статусом ожидания`
`-n вывод в цифровом виде, без dns имен`

## Part 9. Установка и использование утилит top, htop
1. Вывод команды `top`

![image](https://github.com/DanilJPG/images/blob/main/30.png?raw=true)

  - uptime – 1 час,
  - количество авторизованных пользователей - 1,
  - среднюю загрузку системы – 1 минута -0,33; 5 минут - 0,09; 15 минут – 0,03 
  - общее количество процессов - 97,
  - загрузку cpu – 0.0,
  - загрузку памяти- 153,
  - pid процесса занимающего больше всего памяти - 1,
  - pid процесса, занимающего больше всего процессорного времени - 1351.

2. htop
- отсортированному по PID, PERCENT_CPU, PERCENT_MEM, TIME;
 
![image](https://github.com/DanilJPG/images/blob/main/31.png?raw=true)

-  отфильтрованному для процесса sshd;

![image](https://github.com/DanilJPG/images/blob/main/32.png?raw=true)

- с процессом syslog, найденным, используя поиск

![image](https://github.com/DanilJPG/images/blob/main/33.png?raw=true)

- с добавленным выводом hostname, clock и uptime

![image](https://github.com/DanilJPG/images/blob/main/34.png?raw=true)

## Использование утилиты fdisk
1. Вывод команды `sudo fdisk -l` с выделенным названием диска, количеством секторов
   
   ![image](https://github.com/DanilJPG/images/blob/main/35.png?raw=true)

## Part 11. Использование утилиты df
1. Использование `df`
- размер раздела – 11758760 Кб,
- размер занятого пространства – 5071924 Кб,
- размер свободного пространства – 6067728 Кб,
- процент использования – 46%.
  
![image](https://github.com/DanilJPG/images/blob/main/36.png?raw=true)

2. Использование `df -Th`
- размер раздела – 12Gb,
- размер занятого пространства – 4.9Gb ,
- размер свободного пространства – 5.8Gb,
- процент использования - 46%.
- ext4 файловая система, являющаяся самой последней версией, с более высокой производительсность, журналированием, с быстрым монтированием и проверкой диска

![image](https://github.com/DanilJPG/images/blob/main/37.png?raw=true)

## Part 12. Использование утилиты du
1. Проверка дискового пространства с помощью du в /var, /home, /var/log

![image](https://github.com/DanilJPG/images/blob/main/38.png?raw=true)

![image](https://github.com/DanilJPG/images/blob/main/39.png?raw=true)

![image](https://github.com/DanilJPG/images/blob/main/40.png?raw=true)

![image](https://github.com/DanilJPG/images/blob/main/41.png?raw=true)

## Part 13. Установка и использование утилиты ncdu
1. Проверка дискового пространства с помощью ncdu в /var, /hom, /var/log

![image](https://github.com/user-attachments/assets/a64500bd-b32c-4046-b612-52dce997c1c4)

![image](https://github.com/user-attachments/assets/2e1c9805-da9f-466f-b41f-15cb65e12dfe)

## Part 14. Работа с системными журналами
1. /var/log/dmesg

![image](https://github.com/user-attachments/assets/a64e879c-a476-44f8-88e0-bd321554d81f)

2. /var/log/syslog

![image](https://github.com/user-attachments/assets/6592cf61-de46-42c0-833e-0f65dcbca706)

3. /var/log/auth.log

![image](https://github.com/user-attachments/assets/d1a3619e-8595-427f-8c1d-f4f75b2c165a)

4. Перезагрузка sshd c логами

![image](https://github.com/user-attachments/assets/44d7617f-93e9-42fb-a942-9f25d13b18a2)

## Part 15. Использование планировщика заданий CRON
1. Добавление в CRON фнукцию uptime каждые 2 минуты

![image](https://github.com/user-attachments/assets/04b6ca8e-835b-4b4b-b992-706d25c3501b)

2. Проверка в логах

![image](https://github.com/user-attachments/assets/e220535c-8447-4a49-bab1-682f5c364ddd)
