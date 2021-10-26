# ВОЙНЫ ЖУКОВ

Buggle Royale всегда в моде. На поле периодически появляются жуки. Все они пытаются съесть друг друга. Когда два жука сближаются достаточно близко, молодой (с большим ID) ест старого.
Каждый кадр жук выбирает себе жертву: ближайшего жука, которого он может съесть.

Танк едет на сафари по заранее сформированному маршруту и стреляет по жукам.

Симуляция заканчивается после 5000 кадров. Esc - выход из игры на любом этапе.

## Сборка:

Всё должно собраться через стандартный Build Solution. Можно использовать Debug и Release, но только x64!
Запуск либо по F5 из студии, либо сам .exe НО **с рабочей директорией установленной в каталог, где лежит BugWars.vcxproj**. Иначе игра не найдёт данные.

## Задание:

Код игры состоит из следующих частей:
* **Фреймворк**. Статическая библиотека. Проект GameBase
* **Игровой код**. Статическая библиотека. Проект BugWars
* **Исполняемый код**. Исполняемый файл. Проект BugWarsGame << Запускать по умолчанию
* **Тесты**. Юнит тесты. Проект BugWarsTest
	
Редактируйте только **игровой код**!
Во фреймворке намеренно оставлен баг, но вы можете его исправить в игровом коде.

В коде игры есть множество проблем. Все их нужно будет исправить, но сделать это нужно в определённом порядке: make it work, make it right, make it fast.

**Make it work**:

* Игра крашит в режиме отладки (Debug)
* Присутствуют утечки памяти. Количество выделенной памяти логируется на выходе. Без утечек оно должно быть равно 0.
	
**Make it right**:

* Жуки и пули ведут себя странно. Вы поймёте, о чём я.
* Танк стреляет всё время в одном направлении. Сделайте так, чтобы он попадал в жуков, стреляя с линейной поправкой на скорость цели. Это не гарантирует 100% точность, но это не страшно.
* Для автоматической проверки функции стрельбы танка, в проекте есть юнит тесты. Поначалу они не будут проходить, но это не помешает вам запустить игру.
	
**Make it fast**:

* Оптимизируйте игру. Чем быстрее она будет работать, тем лучше. Для удобства тестирования, игру можно запускать с параметром -lock60fps. 

	
Код написан без инкапсулирования - хорошие техники ООП не являются предметом данного упражнения.  
В нём намеренно допущены ошибки и неточности - исправляйте по мере обнаружения.  
Кое-где есть пара комментариев на английском - это скорее декорация. Считайте документацией сам код.  
Следовать стилю не обязательно, но приветствуется.  
К проекту подключён PIX, и в паре мест расставлены маркеры для примера. Можете использовать PIX для профилирования.  
Обратите внимание на функции логирования: вы можете их использовать. Печать идёт в консоль и в Debug Output студии. Класс Point умеет печатать себя в логе. Кликните дважды на сообщение, чтобы перейти к строке в коде. Но помните, что объёмное логгирование замедлит игру.
Игровые объекты знают свой тип - пример его проверки есть в коде.
Скорости указаны в пикселях/с.  
Время обычно считается кадрами.  
Для анимации в кадрах используется фиксированное время равное dt=~16 миллисекундам. Оно не зависит от того, сколько времени прошло между кадрами на самом деле. При запуске с -lock60fps, должна получиться плавная анимация (при условии, что игра не тормозит). Бенчмарк будет проводиться без этого параметра.  
Полная история взаимных поеданий жуков проверяться не будет - в конце концов, реально только то, что видел игрок. Считайте это подсказкой.  
Внимание: могут присутствовать ошибки, которых я не планировал. Если возникают сомнения - пишите в ЛС на Слаке. Но не в групповой чат, чтобы не спойлерить другим студентам.  
  
**Good luck, have fun**.
