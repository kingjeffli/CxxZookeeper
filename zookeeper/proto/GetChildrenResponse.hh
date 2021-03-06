// File generated by hadoop record compiler. Do not edit.

#ifndef GetChildrenResponse_HH_
#define GetChildrenResponse_HH_

#include "Efc.hh"
#include "../../jute/inc/ERecord.hh"
#include "../../jute/inc/EBinaryInputArchive.hh"
#include "../../jute/inc/EBinaryOutputArchive.hh"
#include "../../jute/inc/ECsvOutputArchive.hh"

namespace efc {
namespace ezk {

class GetChildrenResponse: public ERecord {
public:
	sp<EList<EString*> > children; //List<String> children;

	GetChildrenResponse() {
	}
	GetChildrenResponse(sp<EList<EString*> > children) {
		this->children = children;
	}
	sp<EList<EString*> > getChildren() {
		return children;
	}
	void setChildren(sp<EList<EString*> > m_) {
		children = m_;
	}
	virtual void serialize(EOutputArchive* a_, const char* tag)
			THROWS(EIOException) {
		a_->startRecord(this, tag);
		{
			a_->startVector(children.get(), JUTE_SIZE(children), "children");
			if (children != null) {
				int len1 = children->size();
				for (int vidx1 = 0; vidx1 < len1; vidx1++) {
					EString* e1 = dynamic_cast<EString*>(children->getAt(vidx1));
					a_->writeString(e1, "e1");
				}
			}
			a_->endVector(children.get(), "children");
		}
		a_->endRecord(this, tag);
	}
	virtual void deserialize(EInputArchive* a_, const char* tag)
			THROWS(EIOException) {
		a_->startRecord(tag);
		{
			sp<EIndex> vidx1 = a_->startVector("children");
			if (vidx1 != null) {
				children = new EArrayList<EString*>();
				for (; !vidx1->done(); vidx1->incr()) {
					EString e1 = a_->readString("e1");
					children->add(new EString(e1));
				}
			}
			a_->endVector("children");
		}
		a_->endRecord(tag);
	}
	virtual EString toString() {
		try {
			EByteArrayOutputStream s;
			ECsvOutputArchive a_(&s);
			a_.startRecord(this, "");
			{
				a_.startVector(children.get(), JUTE_SIZE(children), "children");
				if (children != null) {
					int len1 = children->size();
					for (int vidx1 = 0; vidx1 < len1; vidx1++) {
						EString* e1 = dynamic_cast<EString*>(children->getAt(vidx1));
						a_.writeString(e1, "e1");
					}
				}
				a_.endVector(children.get(), "children");
			}
			a_.endRecord(this, "");
			s.write('\0');
			return (char*) s.data();
		} catch (EThrowable& ex) {
			ex.printStackTrace();
		}
		return "ERROR";
	}
	void write(EDataOutput* out) THROWS(EIOException) {
		EBinaryOutputArchive archive(out);
		serialize(&archive, "");
	}
	void readFields(EDataInput* in) THROWS(EIOException) {
		EBinaryInputArchive archive(in);
		deserialize(&archive, "");
	}
	virtual int compareTo(EObject* peer_) THROWS(EClassCastException) {
		throw EUnsupportedOperationException(__FILE__, __LINE__,
				"comparing GetChildrenResponse is unimplemented");
	}
	virtual boolean equals(EObject* peer_) {
		GetChildrenResponse* peer = dynamic_cast<GetChildrenResponse*>(peer_);
		if (!peer) {
			return false;
		}
		if (peer_ == this) {
			return true;
		}
		boolean ret = false;
		ret = children->equals(peer->children.get());
		if (!ret)
			return ret;
		return ret;
	}
	virtual int hashCode() {
		int result = 17;
		int ret;
		ret = children->hashCode();
		result = 37 * result + ret;
		return result;
	}
	static EString signature() {
		return "LGetChildrenResponse([s])";
	}
};

} /* namespace ezk */
} /* namespace efc */
#endif /* GetChildrenResponse_HH_ */
