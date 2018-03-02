// File generated by hadoop record compiler. Do not edit.

#ifndef QuorumPacket_HH_
#define QuorumPacket_HH_

#include "Efc.hh"
#include "../../../jute/inc/ERecord.hh"
#include "../../data/Id.hh"

namespace efc {
namespace ezk {

class QuorumPacket: public ERecord {
public:
	int type;
	llong zxid;
	sp<EA<byte> > data;
	sp<EList<sp<Id> > > authinfo;

	QuorumPacket() {
	}
	QuorumPacket(int type, llong zxid, sp<EA<byte> > data, sp<EList<sp<Id> > > authinfo) {
		this->type = type;
		this->zxid = zxid;
		this->data = data;
		this->authinfo = authinfo;
	}
	int getType() {
		return type;
	}
	void setType(int m_) {
		type = m_;
	}
	llong getZxid() {
		return zxid;
	}
	void setZxid(llong m_) {
		zxid = m_;
	}
	sp<EA<byte> > getData() {
		return data;
	}
	void setData(sp<EA<byte> > m_) {
		data = m_;
	}
	sp<EList<sp<Id> > > getAuthinfo() {
		return authinfo;
	}
	void setAuthinfo(sp<EList<sp<Id> > > m_) {
		authinfo = m_;
	}
	virtual void serialize(EOutputArchive* a_, const char* tag)
			THROWS(EIOException) {
		a_->startRecord(this, tag);
		a_->writeInt(type, "type");
		a_->writeLLong(zxid, "zxid");
		a_->writeBuffer(data.get(), "data");
		{
			a_->startVector(authinfo.get(), JUTE_SIZE(authinfo), "authinfo");
			if (authinfo != null) {
				int len1 = authinfo->size();
				for (int vidx1 = 0; vidx1 < len1; vidx1++) {
					sp<Id> e1 = dynamic_pointer_cast<Id>(authinfo->getAt(vidx1));
					a_->writeRecord(e1.get(), "e1");
				}
			}
			a_->endVector(authinfo.get(), "authinfo");
		}
		a_->endRecord(this, tag);
	}
	virtual void deserialize(EInputArchive* a_, const char* tag)
			THROWS(EIOException) {
		a_->startRecord(tag);
		type = a_->readInt("type");
		zxid = a_->readLLong("zxid");
		data = a_->readBuffer("data");
		{
			sp<EIndex> vidx1 = a_->startVector("authinfo");
			if (vidx1 != null) {
				authinfo = new EArrayList<sp<Id> >();
				for (; !vidx1->done(); vidx1->incr()) {
					sp<Id> e1 = new Id();
					a_->readRecord(e1.get(), "e1");
					authinfo->add(e1);
				}
			}
			a_->endVector("authinfo");
		}
		a_->endRecord(tag);
	}
	virtual EString toString() {
		try {
			EByteArrayOutputStream s;
			ECsvOutputArchive a_(&s);
			a_.startRecord(this, "");
			a_.writeInt(type, "type");
			a_.writeLLong(zxid, "zxid");
			a_.writeBuffer(data.get(), "data");
			{
				a_.startVector(authinfo.get(), JUTE_SIZE(authinfo), "authinfo");
				if (authinfo != null) {
					int len1 = authinfo->size();
					for (int vidx1 = 0; vidx1 < len1; vidx1++) {
						sp<Id> e1 = dynamic_pointer_cast<Id>(authinfo->getAt(vidx1));
						a_.writeRecord(e1.get(), "e1");
					}
				}
				a_.endVector(authinfo.get(), "authinfo");
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
				"comparing QuorumPacket is unimplemented");
	}
	virtual boolean equals(EObject* peer_) {
		QuorumPacket* peer = dynamic_cast<QuorumPacket*>(peer_);
		if (!peer) {
			return false;
		}
		if (peer_ == this) {
			return true;
		}
		boolean ret = false;
		ret = (type == peer->type);
		if (!ret)
			return ret;
		ret = (zxid == peer->zxid);
		if (!ret)
			return ret;
		ret = bufEquals(data.get(), peer->data.get());
		if (!ret)
			return ret;
		ret = authinfo->equals(&peer->authinfo);
		if (!ret)
			return ret;
		return ret;
	}
	virtual int hashCode() {
		int result = 17;
		int ret;
		ret = (int) type;
		result = 37 * result + ret;
		ret = (int) (zxid^(((ullong) zxid)>>32));
		result = 37 * result + ret;
		ret = EArrays::toString(data.get()).hashCode();
		result = 37 * result + ret;
		ret = authinfo->hashCode();
		result = 37 * result + ret;
		return result;
	}
	static EString signature() {
		return "LQuorumPacket(ilB[LId(ss)])";
	}
};

} /* namespace ezk */
} /* namespace efc */
#endif /* QuorumPacket_HH_ */