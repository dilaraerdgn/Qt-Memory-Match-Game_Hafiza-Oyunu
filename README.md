# Qt Memory Match Game (Hafıza Oyunu)

Bu proje, **C++** ve **Qt Framework** kullanılarak geliştirilmiş klasik bir hafıza kartı oyunudur. Proje, bir masaüstü uygulamasında oyun mantığının nasıl kurulacağını, sinyal-slot mekanizmalarını ve dinamik arayüz yönetimini sergilemek amacıyla hazırlanmıştır.

---

## Öne Çıkan Özellikler

- **Dinamik Kart Yönetimi:** `QPushButton` sınıfından türetilen özel `Card` sınıfı ile kartların durum yönetimi (açık/kapalı/eşleşti) sağlanmıştır.
- **Zamanlayıcı Kontrolü (QTimer):** Yanlış eşleşen kartların kullanıcıya kısa bir süre gösterilip otomatik olarak kapanması için `QTimer` kullanılmıştır.
- **Algoritmik Karıştırma:** `QRandomGenerator` kullanılarak her yeni oyunda kartların rastgele bir düzende dizilmesi sağlanmıştır.
- **Hata Takibi:** Kullanıcının yaptığı başarısız tahmin sayısı gerçek zamanlı olarak arayüzde güncellenmektedir.

---

## Teknik Detaylar

- **Framework:** Qt 5 / Qt 6
- **Dil:** C++
- **Arayüz Tasarımı:** `mainwindow.ui` ve `QGridLayout` ile responsive (esnek) yerleşim.
- **Olay Yönetimi (Event Handling):** `mousePressEvent` override edilerek kart tıklama davranışları özelleştirilmiştir.
- **Kaynak Yönetimi:** Proje görselleri Qt Resource System (`.qrc`) üzerinden yönetilmektedir.

---

## 📂 Dosya Yapısı

```text

├── main.cpp
├── mainwindow.cpp  # Oyun ana mantığı ve timer yönetimi
├── card.cpp        # Kart davranışları ve sinyalleri
└── mainwindow.ui   # Arayüz tasarımı

├── images/         # Kart görselleri ve arka plan
└── resources.qrc   # Qt Kaynak dosyası
MemoryGame.pro      # Proje yapılandırma dosyası
