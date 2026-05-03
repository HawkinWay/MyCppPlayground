// a concurrency primitive like mutex

class Logger{
	std::once_flag _once;
	std::optional<NetworkConnection> _conn;

	NetworkConnection& getConn(){
		std::call_once(_once, [](){ _coon = NetworkConnection(defaultHost); });
	}
	return *_conn;
}
