Rất vui được tiếp tục với bạn. Chúng ta sẽ đi thật kỹ vào **Tìm kiếm nhị phân**, một trong những thuật toán tìm kiếm hiệu quả và quan trọng nhất.

***

### **Phần 5: Thuật toán Tìm kiếm nhị phân (Binary Search)**

Đây là một thuật toán có hiệu quả vượt trội so với Tìm kiếm tuyến tính, nhưng nó đi kèm một điều kiện tiên quyết rất quan trọng.

#### **1. Điều kiện áp dụng**

* [cite_start]Thuật toán này **chỉ có thể được áp dụng trên một danh sách (mảng) đã được sắp xếp thứ tự** (ví dụ: sắp xếp tăng dần hoặc giảm dần)[cite: 253, 263]. Đây là yêu cầu bắt buộc.

#### **2. Ý tưởng cốt lõi: "Chia để trị" (Divide and Conquer)**

[cite_start]Binary Search hoạt động dựa trên chiến lược "chia để trị"[cite: 254]. Thay vì kiểm tra từng phần tử một, nó sẽ liên tục chia đôi không gian tìm kiếm cho đến khi tìm thấy kết quả.

[cite_start]Cụ thể, ý tưởng của thuật toán là[cite: 255, 256, 257, 258, 259]:
* **Bước 1**: Bắt đầu tìm kiếm tại phần tử nằm chính giữa của mảng.
* **Bước 2**: So sánh giá trị của phần tử giữa với giá trị cần tìm (gọi là `x`).
    * Nếu `phần tử giữa == x` thì đã tìm thấy, kết thúc.
    * Nếu `x < phần tử giữa`, thì `x` chỉ có thể nằm ở nửa đầu của mảng. Ta loại bỏ hoàn toàn nửa sau và lặp lại tìm kiếm trên nửa đầu.
    * Nếu `x > phần tử giữa`, thì `x` chỉ có thể nằm ở nửa sau của mảng. Ta loại bỏ hoàn toàn nửa đầu và lặp lại tìm kiếm trên nửa sau.
* **Bước 3**: Quá trình này được lặp lại cho tới khi tìm thấy `x`, hoặc cho tới khi không gian tìm kiếm không còn phần tử nào.

#### **3. Các bước của thuật toán (Cài đặt không đệ quy)**

[cite_start]Giả sử ta có mảng `a`, tìm kiếm giá trị `value` trong đoạn từ chỉ số `first` đến `last`[cite: 276].
1.  **Khởi tạo**: `first = 0`; [cite_start]`last = n - 1` (với `n` là số phần tử)[cite: 277].
2.  [cite_start]**Vòng lặp**: Lặp lại các bước sau chừng nào `first <= last` (nghĩa là đoạn tìm kiếm vẫn còn phần tử)[cite: 284].
    a.  [cite_start]**Tìm vị trí giữa**: `middle = (first + last) / 2`[cite: 279].
    b.  **So sánh**:
        * Nếu `a[middle] == value`: Tìm thấy! [cite_start]Trả về `middle`[cite: 281].
        * Nếu `value < a[middle]`: `value` nằm ở nửa bên trái. [cite_start]Ta cập nhật `last = middle - 1`[cite: 283].
        * Nếu `value > a[middle]`: `value` nằm ở nửa bên phải. [cite_start]Ta cập nhật `first = middle + 1`[cite: 283].
3.  **Kết thúc**: Nếu vòng lặp kết thúc mà chưa tìm thấy (tức là `first > last`), có nghĩa là `value` không có trong mảng. [cite_start]Trả về `-1`[cite: 286].

#### **4. Minh họa**

Hãy xem ví dụ trong slide: Tìm `X = 2` trong mảng `A = {1, 2, 4, 6, 7, 9, 10}`.

* **Lần 1**:
    * `first = 0`, `last = 6`.
    * `middle = (0 + 6) / 2 = 3`. `A[3]` có giá trị là `6`.
    * Ta thấy `X=2 < A[middle]=6`. Vậy ta chỉ cần tìm ở nửa bên trái.
    * Cập nhật `last = middle - 1 = 2`.

* **Lần 2**:
    * Đoạn tìm kiếm bây giờ là `first = 0`, `last = 2`.
    * `middle = (0 + 2) / 2 = 1`. `A[1]` có giá trị là `2`.
    * Ta thấy `X=2 == A[middle]=2`.
    * [cite_start]**Tìm thấy tại vị trí 1!** [cite: 339]

#### **5. Độ phức tạp**

[cite_start]Vì mỗi lần so sánh, thuật toán loại bỏ một nửa số phần tử còn lại, nên nó cực kỳ nhanh[cite: 385].
* [cite_start]**Tốt nhất**: `O(1)` – tìm thấy ngay ở lần so sánh đầu tiên[cite: 386, 387].
* [cite_start]**Trung bình & Xấu nhất**: `O(log₂N)` – đây là ưu điểm lớn nhất của Tìm kiếm nhị phân so với Tìm kiếm tuyến tính (O(N))[cite: 383, 384].

#### **6. Lưu ý về Cài đặt**

* [cite_start]Thuật toán này có thể được cài đặt bằng vòng lặp (như các bước ở trên) hoặc bằng **đệ quy**[cite: 375].
* Một lưu ý quan trọng trong slide là: Tìm kiếm nhị phân không hiệu quả trên danh sách liên kết đơn thông thường. [cite_start]Để áp dụng ý tưởng này cho cấu trúc liên kết, người ta thường dùng một cấu trúc dữ liệu khác gọi là **Cây nhị phân tìm kiếm (Binary Search Tree)**[cite: 325].

Chúng ta đã đi rất kỹ về Tìm kiếm nhị phân. Bạn có câu hỏi nào không, hay đã sẵn sàng để khám phá thuật toán cuối cùng trong bài giảng, **Tìm kiếm nội suy (Interpolation Search)**?