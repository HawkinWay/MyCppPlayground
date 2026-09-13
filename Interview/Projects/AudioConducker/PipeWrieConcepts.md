# PipeWire Concepts

### Objects

- Server/Daemon
- Core (There can only be one core per server and it has the identifier/ID 0)
- Client
- Node
- Port
- Proxy
- Link
- Rigistry
- Listener

### Workflow

> *PipeWire Server/Daemon's lifecycle management is system-level. So there are no pw_server_destory/pw_daemon_destroy method. It always exists and handle queue events like a system, like suspendinng requests etc.*

Applications such as music players(like Spotify, Tidal) and browsers(like Firefox, Chrome) can be regarded as clients of PipeWire. When a client is started, it will connect to PipeWire's socket(/run/user/1000/pipewire-0). The PipeWire Server then creates a `Client object` and a `Core Proxy` for it. Through core proxy, the client can get `Registry Proxy`.  

A client can request to create a `Node`(like `pw_core_create_object`). After being created by server, node will be rigistried to `Rigistry` and then be a `Global Object` with a globally unique ID.

---

## Lifecycle

pw_init  

pw_main_loop_new  

pw_context_new  

pw_context_connect  

pw_core_get_registry  

pw_core_add_listener  

pw_main_loop_run  

======== *PipeWire main loop*(**Asynchronous**) ========      

Server events arrived  

Listener callback triggered  

Handle events/Update statement  

=============================================    

pw_main_loop_quit  

pw_proxy_destroy  

pw_core_disconnect  

pw_core_destroy  

pw_main_loop_destroy  

pw_deinit  

---

## Synchronous

roundtrip()
