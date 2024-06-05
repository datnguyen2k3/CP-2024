"""
Hãy viết hàm lập trình gửi tài liệu cho người review

Đầu vào:
Danh sách tài liệu được gửi theo thời gian (
    document_id, # id document
    category_id, # 
    send_at, # time send
    completed_time
    ),
Danh sách người tham gia room review theo thời gian (user_id, category_id, join_at)

Đầu ra
Danh sách user đã nhận được những bài viết nào: (user_id, list<document_id>) day tai lieu cho nguoi review

Thứ tự ưu tiên gửi tài liệu từ cao xuống thấp

Ưu tiên gửi tài liệu cho người có cùng category_id, sau do send_at som nhat

Ưu tiên theo thời gian người join room trước hoặc hoàn thành review gần nhất.

Mỗi người chỉ nhận tối đa 2 tài liệu một lúc.
"""

"""
tap hop tai lieu
+ them tai lieu
+ xoa tai lieu


"""

import heapq
import collections
from pydoc import doc

from distutils import core

def get_review_documents(documents, users):
    documents_heap_by_category = collections.defaultdict(list)
    documents_heap = []
    documents_reviewed_set = set()
    document_review_by_user = collections.defaultdict(list)

    users_heap = [(user_join_at, user_id, user_category_id, 0) for user_id, user_category_id, user_join_at in users]
    heapq.heapify(users_heap)

    documents.sort(key=lambda document:document[2])
    users.sort(key=lambda user:user[2])

    current_document_index = 0

    def review_document(document, user):
        nonlocal users_heap, documents_reviewed_set, document_review_by_user

        document_send_at, document_id, document_completed_time = document
        user_join_at, user_id, user_category_id, user_reviews = user

        documents_reviewed_set.add(document_id)
        document_review_by_user[user_id].append(document_id)
        user_reviews += 1

        print(document_send_at, user_join_at, document_id, user_id)

        if user_reviews == 1:
            heapq.heappush(
                users_heap,
                (
                    user_join_at + document_completed_time,
                    user_id,
                    user_category_id,
                    user_reviews,
                ),
            )

    while users_heap:
        user_join_at, user_id, user_category_id, user_reviews = heapq.heappop(users_heap)

        while (
            current_document_index < len(documents) and
            documents[current_document_index][2] <= user_join_at
        ):
            document_id, document_category_id, document_send_at, document_completed_time = documents[current_document_index]

            heapq.heappush(
                documents_heap_by_category[document_category_id],
                (document_send_at, document_id, document_completed_time),
            )

            heapq.heappush(
                documents_heap,
                (document_send_at, document_id, document_completed_time),
            )

            current_document_index += 1

        if documents_heap_by_category[user_category_id]:
            document_send_at, document_id, document_completed_time = heapq.heappop(documents_heap_by_category[user_category_id])
            print(1)
            review_document(
                (document_send_at, document_id, document_completed_time),
                (user_join_at, user_id, user_category_id, user_reviews),
            )

            continue

        while documents_heap and documents_heap[0][1] in documents_reviewed_set:
            heapq.heappop(documents_heap)

        if not documents_heap:
            if current_document_index == len(documents):
                break

            (
                document_id,
                document_category_id,
                document_send_at,
                document_completed_time,
            ) = documents[current_document_index]
            current_document_index += 1

            print(2)
            review_document(
                (document_send_at, document_id, document_completed_time),
                (user_join_at, user_id, user_category_id, user_reviews),
            )

            continue

        document_send_at, document_id, document_completed_time = heapq.heappush(documents_heap)
        print(3)
        review_document(
            (document_send_at, document_id, document_completed_time),
            (user_join_at, user_id, user_category_id, user_reviews),
        )

    return list(document_review_by_user.items())


# List<Document> documents = Arrays.asList( new Document(1, 1, 1000, 2000), new Document(2, 1, 1100, 2100), new Document(3, 2, 1200, 2200), new Document(4, 2, 1300, 2300), new Document(5, 1, 1400, 2400) ); List<User> users = Arrays.asList( new User(1, 1, 900), new User(2, 1, 950), new User(3, 2, 1000), new User(4, 2, 1050) );


print(get_review_documents(
    [(1, 1, 1000, 2000), (2, 1, 1100, 2100), (3, 2, 1200, 2200), (4, 2, 1300, 2300), (5, 1, 1400, 2400)],
    [(1, 1, 900), (2, 1, 950), (3, 2, 1000), (4, 2, 1050)]
))

# java core multithread 
# flat map 
# spring 
