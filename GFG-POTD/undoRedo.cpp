class Solution {
  public:
    stack<char> s;
    string doc="";
    void append(char x) {
        // append x into document
        doc+= x;
    }

    void undo() {
        // undo last change
        s.push(doc[doc.length()-1]);
        doc = doc.substr(0, doc.length()-1);
    }

    void redo() {
        // redo changes
        if(!s.empty()){
            char top = s.top();
            doc += top;
            s.pop();
        }
    }

    string read() {
        // read the document
        return doc;
    }
};