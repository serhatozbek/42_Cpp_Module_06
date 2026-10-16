# C++ Modül 06 — 42 Piscine

Tip dönüşümü, pointer yorumlama ve RTTI. Üç aşamalı egzersiz: tip sistemi manipülasyonu.

| Ex | Sınıf | Konsept |
|---|---|---|
| ex00 | `ScalarConverter` | Implicit/explicit dönüşümler, pseudo-destructor |
| ex01 | `Serializer` | `reinterpret_cast`, pointer serileştirme |
| ex02 | `A`, `B`, `C` | Kalıtım, `dynamic_cast`, RTTI |

**Kazanımlar:**
- `reinterpret_cast` ile raw pointer/bit manipülasyonu
- `dynamic_cast` ile güvenli downcast
- Sanal fonksiyon olmadan tip tanımlama
- Template pseudo-destructor çağrıları
- String'den tipe dönüşüm edge case'leri

## Derleme

```bash
cd cpp6/ex00 && make && ./convert "42"
```

---

⚠️ **Sorumluluk Reddi**
Bu repository'deki çözümler tamamen eğitim ve portföy amaçlıdır. 42'nin onur kuralları gereği, Common Core sürecindeki öğrencilerin çözümleri birebir kopyalaması kesinlikle yasaktır. Buradaki kodlar, bu modülü tamamlamış biri olarak gelişimi göstermek ve gelecekteki projeler için bir referans noktası oluşturmak amacıyla paylaşılmıştır.
