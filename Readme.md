## Part1. Установка ОС
- Проверка версии Ubuntu

![Ubuntu 20.04](https://github.com/user-attachments/assets/e8327404-e674-44a8-ad17-2c746f1f3f8b)

## Part2. Создание пользователя
- Команда создания пользователя test добавление его в групппу adm

![Команда создания пользователя test добавление его в групппу adm](https://github.com/user-attachments/assets/b9db3076-842c-4bbf-b7eb-0e32487f0dcb)

- Вывод команды проверки пользователя test

![Вывод команды проверки пользователя test](https://github.com/user-attachments/assets/b45e1f7c-07ac-4d50-abde-31cfb3f4e09c)
## Part3. Настройка сети ОС
1. Установи временную зону, соответствующую твоему текущему местоположению
- `sudo ln -sf /usr/share/zoneinfo/Europe/Moscow /etc/localtime`, `timedatectl`

2. Выведи названия сетевых интерфейсов с помощью консольной команды
   ![image](https://github.com/user-attachments/assets/d1c95fc8-5f46-49e3-a257-759230dcbc36)

- lo - сетевой интерфейс может быть виртуальным, который отвечает за сетевое общение программ операционной системы данной ВМ. lo – сетевой виртуальный интерфейс который используется по умолчанию в Linux. Он используется для отладки сетевых программ и запуска серверных приложений на локальной машине. С этим интерфейсом всегда связан адрес 127.0.0.1 и него есть dns – localhost. Привязка находится по адресу /etc/hosts. Используется самой системой для тестирования сетевых приложений без выхода в реальную сеть. Например, вы запускаете сервер и клиент на одном компьютере, они могут общаться через 127.0.0.1

3. Используя консольную команду, получи ip адрес устройства, на котором ты работаешь, от DHCP-сервера
- `ip route` используется для проверки маршрутов по передачи данных, `grep default` отображает значение шлюза через который будут оставлены пакеты по умолчанию   
   ![image](https://github.com/user-attachments/assets/7ca383dd-c9b1-4144-ad40-77a5e7623f6b)
- DHCP –динамический протокол настройки хоста
4. Определи и выведи на экран внешний ip-адрес шлюза (ip) и внутренний IP-адрес шлюза, он же ip-адрес по умолчанию (gw)
- `ip addr show` или `ip a`
    ![image](https://github.com/user-attachments/assets/04929cd0-9963-4ad3-a68c-5b34f3537935)
5. Задай статичные (заданные вручную, а не полученные от DHCP-сервера) настройки ip, gw, dns (используй публичный DNS-серверы, например 1.1.1.1 или 8.8.8.8).
- Для установки постояннх значений настроектребуется:
- изменить `config` файл, взависимости от системы(в etc/netplan)

    ![image](https://github.com/user-attachments/assets/3af26ed8-afa1-4b49-afcd-a43e875cd4c4)
    
- установить необходимые значения:

    ![image](https://github.com/user-attachments/assets/1c528f66-a6ec-4028-bf12-66f9ae39dc42)
    
- убедится после перезагрузки в правильности:

    ![image](https://github.com/user-attachments/assets/eaa17773-83fb-424e-b85a-29532c1aa464)
  
- пинг удаленных хостов

     ![image](https://github.com/user-attachments/assets/8d081775-3f35-4bc5-9ed9-517b348fb18d)
## Part4. Обновление ОС
1. Обновление системных пакетов
   ![image](https://github.com/user-attachments/assets/014e8c96-509e-48fd-b224-1e3e4c0fa1b4)

## Part 5. Использование команды sudo
1. Добавление в группу sudo gпользователя test(для выполнения команд как root, предоставление прав su)
   ![image](https://github.com/user-attachments/assets/e88ca2eb-9564-4915-bd35-a9926bf3f9dd)
2. `sudo hostnamectl set-hostname новое_имя`

3. Проверка cat /etc/hostname
   
   ![image](https://github.com/user-attachments/assets/a6d246c1-1905-47df-807b-07596d36a2be)

   
## Part 6. Установка и настройка службы времени
1. Проверка часового пояса и синхронизации
   
   ![image](https://github.com/user-attachments/assets/88500da5-f4b4-4be9-b8d9-d2343361531d)

   ![image](https://github.com/user-attachments/assets/f5322964-9c21-4b41-a928-da9a61692208)


## Part 7. Установка и использование текстовых редакторов
1. Создание файлов и выход с сохранением из них
- Joe: `Ctrl+K+X`
   
   ![image](https://github.com/user-attachments/assets/54b32074-f71b-4b17-98c3-0c0efaaa8e7b)
   
- nano: `Ctrl+X+Y`
   
   ![image](https://github.com/user-attachments/assets/0c3abff2-1af4-4b4a-8c58-128f822eae42)
   
- Vim: `:wq`
   
   ![image](https://github.com/user-attachments/assets/7d9fe677-e289-4395-a037-c01746a73c18)

2. Замена сожержимого файлов, выход без сохранения
- Joe: `Ctrl+K+Q+n`
   
   ![image](https://github.com/user-attachments/assets/68df6a16-3ee4-4b70-808d-ac237fdb3500)

- nano: `Ctrl+X+n`

   ![image](https://github.com/user-attachments/assets/b609989f-71d0-443c-acbd-3e1dd261919f)

- Vim: `:q!`

   ![image](https://github.com/user-attachments/assets/fa3fb833-4cfa-4a86-816b-7d225550b0fa)

3. Функции поиска слова и его замена
- Joe:   `^K+F+ввод поискового слова+B`
         `^K+F+R+старое слово + новое слово+y`

   ![image](https://github.com/user-attachments/assets/73a1db4b-4d56-4b68-a32b-d7007d400e89)

   ![image](https://github.com/user-attachments/assets/32adf2fe-9dd2-46c5-b490-eb843bcbaba2)

- nano: `^w+fets(слово для поиска)`
        `^\+fest(old name)+castaaa(new name+enter)+y`
  
  ![image](https://github.com/user-attachments/assets/26cce4de-b8c1-4484-a0cc-66ac061061ad)

  ![image](https://github.com/user-attachments/assets/5d68c54b-86df-4141-9fd3-81c964fbf26e)

  - Vim: `/lot(слово для описка)`
  `:%s/old_name/new_name/`
 
   ![image](https://github.com/user-attachments/assets/d90929e4-6f8e-4eed-9af0-13609e6a8ea0)

   ![image](https://github.com/user-attachments/assets/e78f0272-b194-43d8-a6ac-d6a6b5462aa3)

## Part 8. Установка и базовая настройка сервиса SSHD
1. `sudo apt install openssh-server` - установка openssh
2. `sudo systemctl enable ssh` - автозагрузка ssh
3. `sudo nano /etc/ssh/sshd_config` + изменение в конфиг-файле на port 2022
4. ps –ef | grep sshd

- Скрины с выводом команд
![image](https://github.com/user-attachments/assets/131d63c1-601f-42ea-9d5a-48231396ba7f)

![image](https://github.com/user-attachments/assets/57386aa3-50c8-402d-ac2f-22ed7313c66a)
`-t показывает только tcp соединения` 
`-a показывает все соединения и порты`
`-n вывод в цифровом виде, без dns имен`

## Part9

## Part10

## Part11

## Part12

## Part13

## Part14

## Part15
