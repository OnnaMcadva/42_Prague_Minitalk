## 42_Prague_Minitalk

struct sigaction - это структура в языке программирования C, которая используется для настройки обработки сигналов в программе. Эта структура включает в себя несколько полей, предназначенных для определения поведения программы в ответ на получение конкретного сигнала. Вот основные поля структуры struct sigaction:

    void (*sa_handler)(int): Это указатель на функцию, которая будет вызвана при получении сигнала. Вместо этого, вы также можете использовать sa_sigaction, если требуется более расширенная обработка сигнала.

    void (*sa_sigaction)(int, siginfo_t *, void *): Альтернатива sa_handler. Это указатель на функцию, которая может принимать три аргумента: номер сигнала, информацию о сигнале (siginfo_t), и указатель void * на дополнительные данные. Это поле используется, например, когда требуется более подробная информация о сигнале.

    sigset_t sa_mask: Это множество сигналов, которые будут заблокированы во время выполнения обработчика сигнала. Это предотвращает повторное прерывание текущего обработчика сигнала другим сигналом.

    int sa_flags: Флаги, определяющие дополнительное поведение. Например, SA_SIGINFO указывает, что sa_sigaction должна использоваться вместо sa_handler.

    void (*sa_restorer)(void): Устаревшее поле, которое ранее использовалось для указания функции восстановления состояния процесса после обработки сигнала. В настоящее время не рекомендуется использовать.

Структура struct sigaction предоставляет механизм для настройки обработки сигналов и позволяет программистам определять, как программа должна реагировать на различные события, такие как получение сигнала пользователем или операционной системой.
